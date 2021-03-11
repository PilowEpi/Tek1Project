#!/usr/bin/env bash

TEST=0
SUCCESS=0

test_sh ()
{
    if [ "$1" = "$2" ] && [ "$3" = "$4" ]; then
        printf "\033[1;32mSuccess test %d (%s)\n\033[0m" $TEST "$5"
        SUCCESS=$((SUCCESS+1))
    else
        printf "\033[1;31mFail test %d (%s)\n\033[0m" $TEST "$5"
        printf "\033[1;29m42sh output: \n\033[0m"
        printf "\033[1;29m================\n\033[0m"
        printf "\033[1;29m%s\n\033[0m" "$1"
        printf "\033[1;29m================\n\033[0m"
        printf "\033[1;29m42sh return value %s\n\n\033[0m" "$3"
        printf "\033[1;29mTcsh output:\n\033[0m"
        printf "\033[1;29m================\n\033[0m"
        printf "\033[1;29m%s\n\033[0m" "$2"
        printf "\033[1;29m================\n\033[0m"
        printf "\033[1;29mTcsh return value %s \n\n\033[0m" "$4"
    fi
    TEST=$((TEST+1))
}

execute ()
{
    SHELL=$(echo -ne "$1"| ./42sh 2>&1)
    RETURN_VALUE=$(echo $?)

    TCSH=$(echo -ne "$1" | /usr/bin/tcsh 2>&1)
    RET_TCSH=$(echo $?)

    test_sh "$SHELL" "$TCSH" "$RETURN_VALUE" "$RET_TCSH" "$1"
}


## SPACE TEST

execute " "
execute "                         "
execute ""
execute "\n"
execute "\t\t\t\t\t\t"
execute "\0"

## BASIC TEST

execute "ls"
execute "cat lol"
execute "abcd"
execute "exxit"

## MEDIUM TEST

execute "ls          -l             |      cat         -e       "
execute "ls                                   -l"
execute "ls           -l                                -a"
execute "     ls             -l      -all     "

## ENV TEST

execute "unsetenv PATH; setenv PATH /bin/ ; ls /"
execute "setenv _toto tata"
execute "setenv 8toto tata"
execute "setenv toto tata titi"
execute "setenv toto= tata"
execute "setenv toto9 tata"
execute "setenv Toto9"
execute "setenv Toto"
execute "setenv Abc Abc"
execute "setenv Zbc Zbc"

## EXIT TEST

execute "exit 0"
execute "exit 1"
execute "exit -1"
execute "exit 100000000"
execute "exit -1000000"
execute "exit -aaaa"
execute "exit abc"
execute "exit 123zijaoizjpoaije"
execute "exit 10; ls"
execute "exit 10; exit 12"
execute "exit     10"

## SEMIC TEST

execute "ls; ls; ls; ls"
execute "ls; ls; ls;"
execute ";"
execute ";;;"
execute "ls; pwd"
execute "ls;ls;ls;ls"

## INIBITOR TEST
execute "echo 'hola\namigo'"
execute "ls 'a\" \"b'"

## LINE FORMATING (space and tabs)
execute " \techo   \t\thello"
execute "\techo hi\t"
execute "ls                  \t-l\t    "
execute "    echo     \"  lol  lol  \"  "

## HARDCORE
execute "cd ; </etc/hosts od -c | grep xx | wc >> /tmp/z -l ; cd - && echo OK"
execute "od < /etc/hosts -c | grep m | wc >> /tmp/z -l; cat /tmp/z"

printf "\n\033[1;34mSuccess: %d/%d\n\033[0m" $SUCCESS $TEST
printf "\033[1;34mFailed: %d/%d\033[0m\n\n" $((TEST-SUCCESS)) $TEST
