#!/bin/bash

[[ -d /proc/$$ ]]

read answer
if [[ "yes" != $answer ]]; then
    echo "answer is not yes!"
else
    echo "answer is yes!"
fi
