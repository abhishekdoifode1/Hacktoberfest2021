import 'dart:math';
class ArmstrongNumbers {
  bool isArmstrongNumber(int num) {
    int numMod = 0;
    int total = 0;
    int firstNum = num;
    List<int> numbers = [];
    if (num == 0) {
      return true;
    } else {
      while (num > 0) {
        numMod = num % 10;
        numbers.add(numMod);
        num = num ~/ 10;
      }
      for (int i = 0; i < numbers.length; i++) {
        total = total + pow(numbers[i], numbers.length).toInt();
      }
      if (total == firstNum)
        return true;
      else
        return false;
    }
  }
}