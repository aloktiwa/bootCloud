package main

import (
	"os"
	"os/exec"
	"fmt"
	"syscall"
	)

func run() {
	fmt.Println("run run run cmd ",os.Args[2:])
	cmd := exec.Command(os.Args[2],os.Args[3:]...)
	cmd.Stdin = os.Stdin
	cmd.Stdout = os.Stdout
	cmd.Stderr = os.Stderr
	cmd.SysProcAttr = &syscall.SysProcAttr{Cloneflags: syscall.CLONE_NEWUTS,}

	must(syscall.Sethostname([],byte
}
func main() {
	switch os.Args[1] {
		case "run":
			run()
			fmt.Printf("run is call\n");
		default:
			panic("help")
	}
}
