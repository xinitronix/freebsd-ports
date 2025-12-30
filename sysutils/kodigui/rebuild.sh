#!/bin/sh

ARG=$(zenity --title="youtube"  --entry --text="Введите хэш коммита")

if [ -z "$ARG" ]; then
  echo "Usage: $0 <string>"
  exit 1
fi

# 1. Оставить -d и удалить всё после него
sed -i '' '/^DISTVERSIONSUFFIX=/ s/\(-g\).*/\1/' Makefile

# 2. Вставить аргумент после -d
sed -i '' "/^DISTVERSIONSUFFIX=/ s/-g/-g$ARG/" Makefile

doas make makesum
doas make reinstall
doas make clean
../../git.sh