for((i=1;;i++)); do
    echo $i
    ./gen > in
    diff -w <(./bit < in) <(./wzo < in) || break
done