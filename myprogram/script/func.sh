myfunc2() {
	    echo "bye $*"
}
# Same as above (alternate syntax)
function myfunc() {
    echo "hello $3"
    echo "hello $#"
}
myfunc2 "John"
myfunc "John" "hi " "233" "jonny"
myfunc2 "John" "hi " "233" "jonny"

