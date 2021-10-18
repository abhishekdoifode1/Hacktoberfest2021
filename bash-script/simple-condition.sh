#!/bin/bash
echo "What's your number?"
read number
echo "Your number is $number"

case $number in
101)
echo "You got 101, congratulations." ;;
202)
echo "You got 202, so close" ;;
404)
echo "You got 404, not found :)" ;;
*)
echo "Sorry, you couldn't find anything." ;;
esac
