#!/bin/sh

cocos compile . -p linux -m release -o ./Bin
cocos run . -p linux -m release -o ./Bin
