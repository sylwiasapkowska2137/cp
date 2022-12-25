#! /usr/bin/env python
#-*- coding: utf8 -*-
# Autor: Przemysław Jakub Kozłowski

# TODO
# Wiele aplikacji
# Dodanie generatora inów
# Dodanie porównywarki outów

import sys, time, getopt, os, glob, re, subprocess, signal, tempfile
reload(sys)
sys.setdefaultencoding('utf-8')

# Funkcje pomocnicze
#TODO Poprawić szybkość
def numeric_cmp(a, b):
    a += chr(0)
    b += chr(0)
    result = None
    for i in range(min(len(a), len(b))):
        if not a[i].isdigit() and not b[i].isdigit():
            if result or a[i] != b[i]:
                return result or cmp(a[i], b[i])
            result = None
        elif a[i].isdigit() and b[i].isdigit():
            result = result or cmp(a[i], b[i])
        else:
            return -1 if (result is not None)^(a[i].isdigit()) else 1
    return 0

def color(msg, *args):
    """
    Formatuje tekst.
    Sposób użycia: color(msg, format1, format2, ... ,formatN).
    """
    args = map(str, args)
    return '\033['+';'.join(args)+'m'+msg+'\033[0m'

def block(msg, *args):
    """
    Wypisuje tekst w blocku (z tłem).
    Sposób użycia: color(msg, format1, format2, ... ,formatN).
    """
    args = map(str, args)

    lines = msg.split('\n')
    first = None
    for i,line in enumerate(lines):
        if line != '':
            first = i
            break
    for i,line in reversed(list(enumerate(lines))):
        if line != '':
            last = i
            break

    if first is not None:
        lines = lines[first:last+1]
    else:
        return ''

    column = max([0]+map(ulen, lines))

    result = ''

    for i,line in enumerate(lines):
        if i != 0:
            result += '\n'
        result += color(ljust(line, column), *args)

    return result

def uncolor(msg):
    return re.sub(r'\033\[[^m]*m', '', msg)

cout = sys.stdout.write
flush = sys.stdout.flush
ulen = lambda msg: len(unicode(uncolor(msg)))
ljust = lambda msg, size: msg+" "*(size-ulen(msg))
rjust = lambda msg, size: " "*(size-ulen(msg))+msg
def center(msg, size):
    msg_len = ulen(msg)
    left = max(0, (size-msg_len)/2)
    right = max(0, size-(left+msg_len))

    return left*" "+msg+" "*right

reportL = lambda msg: color(msg, 37) #TODO Poprawić, żeby ładniej wyglądało
reportR = lambda msg: color(msg, 1, 33)
errorC = lambda msg: color(msg, 1, 31)
blockC = lambda msg: block(msg, 40)

def report(msg1, msg2):
    print(reportL(msg1)+": "+reportR(msg2))

def error(msg, critical=True):
    print (errorC("\nBŁĄD: "+msg+"!"))
    if critical:
        exit()

# Klasy
class Timer(object):
    """Stoper"""

    start_time = None
    end_time = None

    def start(self):
        self.start_time = time.time()

    def stop(self):
        self.end_time = time.time()

    def get_time(self):
        return (self.end_time or time.time())-self.start_time

class Test(object):
    test_file = None

    def __init__(self, test_file):
        self.test_file = test_file

    @property
    def name(self):
        return os.path.relpath(self.test_file, os.curdir)

    @property
    def in_file(self):
        return self.test_file+'.in'

    @property
    def out_file(self):
        return self.test_file+'.out'

    def __cmp__(self, other):
        return numeric_cmp(self.test_file, other.test_file)

# Stałe
LOGO = \
    color('<'*30, '1', '36')+ \
    color('PJKjudge', '1', '4', '34')+ \
    color(">"*30, '1', '36')

HELP = "" #TODO Poprawić, żeby ładniej wyglądało
HELP += color("SKŁADNIA", 1)
HELP += "\n\t"+color("PJKjudge.py ", 1)+' ['+color("OPCJE", 1)+'] '+ \
    color("aplikacja katalog_testów1 katalog_testów2 ... katalog_testówN", 1)

HELP += "\n"+color("OPIS", 1)
HELP += "\n\t"+color("aplikacja".ljust(15), 1)+' '+'aplikacja do sprawdzenia'
HELP += "\n\t"+color(u"katalog_testów".ljust(15), 1)+" "+ \
    "katalog testów (wyszukuje rekurencyjnie) lub test"

HELP += "\n"+color("OPCJE", 1)
HELP += "\n\t"+color("-t", 1)+13*" "+color("timelimit", 4)+2*" "+ \
"limit czasu (s)"
HELP += "\n\t"+color("-m", 1)+13*" "+color("memlimit", 4)+3*" "+ \
"limit pamięci (MiB)"
HELP += "\n\t"+color("--oitimetool", 1)+3*" "+color("oitimetool", 4)+" "+ \
"używa OiTimeTool (podać ścieżkę do katalogu OiTimeTool)"

HELP += "\n"+color("UWAGI", 1)
HELP += "\n\t"+color("Jeśli używane jest OiTimeTool limit czasu oznacza "+ \
"maksymalny czas działania OiTimeTool, a limit pamięci oznacza maksymalną "+ \
"pamięć używaną przez OiTimeTool.", 1)
HELP += "\n\t"+color("Limit czasu i pamięci może być ułamkiem.", 1)


HELP += "\n"+reportL("Autor:")+' '+color("Przemysław Jakub Kozłowski", 1, 36)

STATUSES = {
    'OK' : ("Zaakceptowany",    ('1','32')),
    'WA' : ("Błędna odpowiedź", ('1','31')),
    'TL':  ("Limit czasu",      ('1','35')),
    'RE' : ("Błąd wykonania",   ('2','31')),
    'ML' : ("Limit pamięci",    ('2','33')),
}
STATUS_ORDER = ('OK', 'WA', 'TL', 'RE',)

# Skrypt
def main():
    # Uruchamianie timera
    script_timer = Timer()
    script_timer.start()

    # Parsowanie opcji
    options = get_options(sys.argv[1:])

    # Wypisywanie loga
    print(LOGO)

    # Wypisywanie pomocy
    if options is None:
        print (HELP)
        exit()

    app_name = options['app_name']
    test_dirs_files = options['test_dirs_files']
    timelimit = options['timelimit']
    memlimit = options['memlimit']
    oitimetool = options['oitimetool']

    if oitimetool is not None:
        oitimetool = os.path.join(oitimetool, 'oitimetool') #TODO Poprawić

    # Sprawdzanie czy istnieją pliki
    if not os.path.exists(app_name):
        error("Nie znaleziono aplikacji \""+app_name+"\"")
    if oitimetool is not None and not os.path.exists(oitimetool):
        error("Nie znaleziono OiTimeTool \""+oitimetool+"\"")
    if oitimetool is not None and not os.path.isfile(oitimetool):
        error("Skrypt oitimetool nie jest plikiem \""+oitimetool+"\"")
    if oitimetool is not None and len(os.path.basename(app_name).split()) > 1:
        error("OiTimeTool nie obsługuje aplikacji z białymi znakami w nazwie"+ \
            " \""+os.path.basename(app_name)+"\"")

    # Testowanie OiTimeTool
    TEST = True # Ustaw to na False, żeby nie testować
    if oitimetool is not None and TEST:
        try:
            cmd = '\"'+oitimetool+'\" test-programs/empty-gcc44'
            test_programs_dir = os.path.join(os.path.dirname(oitimetool),
                'test-programs/')

            if not os.path.isdir(test_programs_dir):
                error("Błąd podczas testowania OiTimeTool."+\
                    "Nie znaleziono katalogu test-programs.")

            p = subprocess.Popen(cmd, shell=True,
                cwd=os.path.dirname(oitimetool),
                stdout=subprocess.PIPE, stderr=subprocess.STDOUT,
                stdin=subprocess.PIPE)
            stdout = p.communicate()[0]
            if stdout != '\ntime: 0.000s\n':
                print(errorC("Błąd podczas testowania OiTimeTool."+ \
                " Po uruchomieniu:"))
                print (blockC(cmd))
                print (errorC("otrzymano na wyjściu:"))
                print (blockC(stdout))
                exit()
        except (StopScript, SystemExit):
            raise
        except:
            error("Błąd podczas testowania OiTimeTool.")

    # Szukanie testów
    tests = get_tests(test_dirs_files)

    # Sortowanie testów
    tests = sorted(tests)

    # Przygotowanie do sprawdzania
    lp_column = 2*len(str(len(tests)))+1
    test_column = max(map(lambda test: ulen(test.name), tests)+[0])
    status_column = max(map(lambda status: ulen(status[0]), STATUSES.values()))
    status_column += 5 # Dla returncode.

    max_app_time = 0.0
    total_app_time = 0.0
    if oitimetool is not None:
        max_ott_time = 0.0
        total_ott_time = 0.0
    total_status_count = dict(zip(STATUSES.keys(), [0]*len(STATUSES)))

    report("Liczba wszystkich testów", str(len(tests)))

    # Sprawdzanie na testach

    try:
        for i, test in enumerate(tests, 1):
            # Wypisywanie numeru i nazwy testu
            cout(ljust(color(str(i)+"/"+str(len(tests)), 2,37), lp_column))
            cout(" "+color(test.name.ljust(test_column), 1))
            flush()
            # Sprawdzanie
            if oitimetool is not None:
                result = ott_judge(oitimetool, app_name, test.in_file, \
                    test.out_file, timelimit, memlimit)
            else:
                result = standard_judge(app_name, test.in_file, test.out_file, \
                    timelimit, memlimit)

            total_status_count[result['status']] += 1

            if result.get('app_time', None) is not None:
                max_app_time = max(max_app_time, result['app_time'])
                total_app_time += result['app_time']

            if result.get('ott_time', None) is not None:
                max_ott_time = max(max_ott_time, result['ott_time'])
                total_ott_time += result['ott_time']

            # Wypisywanie wyniku
            sd = STATUSES[result['status']][0]
            if result.has_key('returncode'):
                sd += "("+str(result['returncode'])+")"
            cout(" "+ljust(color(sd,*STATUSES[result['status']][1]),
                status_column))

            if result.get('app_time', None) is not None:
                cout(" "+color('%.3f'%result['app_time']+"s", 1))
            else:
                cout(" "+color("------", 1))

            if oitimetool is not None:
                if result.get('ott_time', None) is not None:
                    cout(" "+color('%.3f'%result['ott_time']+"s", 1))
                else:
                    cout(" "+color("------", 1))

            if result.get('run_out', None) is not None:
                b = blockC(result['run_out'])
                if b:
                    cout('\n'+b)

            cout("\n")
    except StopScript:
        cout("\n"+color("Przerwano!", 1)+"\n")

    # Wypisywanie raportu
    cout(rjust(reportL("MAX:"), test_column+status_column+lp_column+2))
    cout(" "+reportR('%.3f'%max_app_time+'s'))
    if oitimetool is not None:
        cout(" "+reportR('%.3f'%max_ott_time+'s'))
    cout("\n")

    cout(rjust(reportL("SUMA:"), test_column+status_column+lp_column+2))
    cout(" "+reportR('%.3f'%total_app_time+'s'))
    if oitimetool is not None:
        cout(" "+reportR('%.3f'%total_ott_time+'s'))
    cout("\n")

    for status in STATUS_ORDER:
        if total_status_count[status] > 0:
            cout(ljust(color(STATUSES[status][0], *STATUSES[status][1]), \
                status_column))
            cout(": "+reportR(str(total_status_count[status])+ \
                " ("+'%.0f'%(100.0*total_status_count[status]/len(tests))+"%)"))
            cout("\n")

    script_timer.stop()
    report("Czas działania skryptu", '%.3f'%script_timer.get_time()+'s')

def get_options(argv):
    """Parsuje opcje."""
    try:
        opt_kwargs, opt_args = getopt.gnu_getopt(argv, 't:m:', ('oitimetool=',))
        opt_kwargs = dict(opt_kwargs)

        if len(opt_args) < 2:
            raise getopt.GetoptError(None)

        if opt_kwargs.has_key('-t'):
            try:
                timelimit = round(float(opt_kwargs['-t']), 3)
            except ValueError:
                raise getopt.GetoptError(None)

            if not 0 < timelimit:
                raise getopt.GetoptError(None)
        else:
            timelimit = None

        if opt_kwargs.has_key('-m'):
            try:
                memlimit = round(float(opt_kwargs['-m']), 3)
            except ValueError:
                raise getopt.GetoptError(None)

            if not 0 < memlimit:
                raise getopt.GetoptError(None)
        else:
            memlimit = None

        if opt_kwargs.has_key('--oitimetool'):
            oitimetool = os.path.abspath(opt_kwargs['--oitimetool'])
        else:
            oitimetool = None

        options = {
            'app_name': os.path.abspath(opt_args[0]),
            'test_dirs_files': map(os.path.abspath, opt_args[1:]),
            'timelimit': timelimit,
            'memlimit': memlimit,
            'oitimetool': oitimetool,
        }
    except getopt.GetoptError:
        options = None

    return options

def get_tests(test_dirs_files):
    tests = []
    test_ins = []

    for test_dir_file in test_dirs_files:
        if os.path.isfile(os.path.splitext(test_dir_file)[0]+'.in'):
            test_ins.append(os.path.splitext(test_dir_file)[0]+'.in')
        else:
            test_ins += glob.glob(test_dir_file+'/*.in')

    for test_in in test_ins:
        if os.path.isfile(test_in[:-3]+'.out'):
            tests.append(Test(test_in[:-3]))
    return tests

def get_process_children(pid):
    p = subprocess.Popen('ps --no-headers -o pid --ppid %d' % pid, shell = True,
              stdout = subprocess.PIPE, stderr = subprocess.PIPE)
    stdout, stderr = p.communicate()
    return [int(p) for p in stdout.split()]

def kill_tree(p):
    if p.poll() is None:
        for pid in get_process_children(p.pid):
            os.kill(pid, signal.SIGKILL)
        p.kill()


#TODO Poprawić
def standard_judge(app_name, test_in, test_out, timelimit, memlimit):
    result = None
    try:
        prog_out = tempfile.mktemp(prefix="PJKjudge")

        if memlimit is not None:
            s_memlimit = str(int(memlimit*1024))
        else:
            s_memlimit = 'unlimited'
        memlimit_cmd = 'ulimit -s '+s_memlimit+';'+ \
            'ulimit -v '+s_memlimit+';'+ \
            'ulimit -m '+s_memlimit+';'

        class TimeLimit(Exception): pass
        def timelimit_handler(signum, frame): raise TimeLimit()
        signal.signal(signal.SIGALRM, timelimit_handler)
        try:
            timer = Timer()
            timer.start()

            if timelimit is not None:
                signal.setitimer(0, timelimit)

            p = subprocess.Popen(memlimit_cmd+'\"'+app_name+'\"'+ \
                ' < \"'+test_in+'\" > \"'+prog_out+'\"',
                shell=True, stdout=subprocess.PIPE, stderr=subprocess.STDOUT,
                stdin=subprocess.PIPE)
            stdout, stderr = p.communicate()

            if timelimit is not None:
                signal.setitimer(0, 0)

            timer.stop()
            app_time = timer.get_time()

            returncode = p.returncode

        except TimeLimit:
            app_time = None
        finally:
            kill_tree(p)

        class Return(Exception): pass
        try:
            if app_time is None:
                result = {
                    'status': 'TL',
                }
                raise Return

            if returncode != 0:
                result = {
                    'status': 'ML' if returncode == 137 else 'RE',
                    'app_time': app_time,
                    'run_out': stdout,
                    'returncode': returncode,
                }
                raise Return

            diff_result = subprocess.call(['diff', '-bBq', test_out, prog_out],
                stdin=subprocess.PIPE, stdout=subprocess.PIPE)

            if diff_result != 0:
                result = {
                    'status': 'WA',
                    'app_time': app_time,
                }
                raise Return

            result = {
                'status': 'OK',
                'app_time': app_time,
            }
            raise Return

        except Return: pass
    finally:
        if os.path.exists(prog_out):
            os.unlink(prog_out)

    return result

#TODO Poprawić
def ott_judge(oitimetool, app_name, test_in, test_out, timelimit, memlimit):
    result = None
    try:
        prog_out = tempfile.mktemp(prefix="PJKjudge")

        if memlimit is not None:
            s_memlimit = str(int(memlimit*1024))
        else:
            s_memlimit = 'unlimited'
        memlimit_cmd = 'ulimit -s '+s_memlimit+';'+ \
            'ulimit -v '+s_memlimit+';'+ \
            'ulimit -m '+s_memlimit+';'

        class TimeLimit(Exception): pass
        def timelimit_handler(signum, frame): raise TimeLimit()
        signal.signal(signal.SIGALRM, timelimit_handler)
        try:
            timer = Timer()
            timer.start()

            if timelimit is not None:
                signal.setitimer(0, timelimit)

            p = subprocess.Popen(memlimit_cmd+ \
                '\"'+oitimetool+'\" '+'./'+os.path.basename(app_name)+ \
                ' < \"'+test_in+'\" > \"'+prog_out+'\"',
                shell=True, cwd=os.path.dirname(app_name),
                stdout=subprocess.PIPE, stderr=subprocess.STDOUT,
                stdin=subprocess.PIPE)
            stdout, stderr = p.communicate()

            if timelimit is not None:
                signal.setitimer(0, 0)

            timer.stop()
            ott_time = timer.get_time()

            returncode = p.returncode
        except TimeLimit:
            ott_time = None
        finally:
            kill_tree(p)

        class Return(Exception): pass
        try:
            if ott_time is None:
                result = {
                    'status': 'TL',
                }
                raise Return

            m = re.compile(r'\ntime: (.*)s\n').match(stdout)
            if m is not None:
                try: float(m.groups()[0])
                except ValueError: m = None

            if m is None or returncode != 0:
                result = {
                    'status' : 'RE',
                    'ott_time': ott_time,
                    'run_out': stdout,
                    'returncode': returncode,
                }
                raise Return

            app_time = float(m.groups()[0])

            diff_result = subprocess.call(['diff', '-bBq', test_out, prog_out],
                stdin=subprocess.PIPE, stdout=subprocess.PIPE)

            if diff_result != 0:
                result = {
                    'status': 'WA',
                    'ott_time': ott_time,
                    'app_time': app_time,
                }
                raise Return

            result = {
                'status': 'OK',
                'ott_time': ott_time,
                'app_time': app_time,
            }
            raise Return

        except Return: pass
    finally:
        if os.path.exists(prog_out):
            os.unlink(prog_out)

    return result

# Uruchamianie skryptu
if __name__ == '__main__':
    # Ustawianie akcji na Ctrl+C.
    class StopScript(Exception): pass
    def interrupt(signum, frame):
        raise StopScript
    signal.signal(signal.SIGINT, interrupt)

    try:
        main()
    except (StopScript, SystemExit):
        pass
    except:
        error('Błąd skryptu', critical=False)
        raise