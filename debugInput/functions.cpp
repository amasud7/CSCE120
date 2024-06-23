# include <stdexcept>
using namespace std;
int Largest(int a, int b, int c) {
  int d = a;
  if (a > d) {
    d = a;
  } 
  if (b > d) {
    d = b;
  } 
  if (c > d) {
    d = c;
  }
  return d;
}

bool SumIsEven(int a, int b) {
  if(((a+b)%2) != 0) {
    return false;
  }
  else {
    return true;
  }
}

int BoxesNeeded(int apples) {
  if (apples < 20) {
    if (apples <= 0) {
      return 0;
    }
    else {
      return 1;
    }

  }
  else if (apples % 20 == 0) {
      return apples / 20;
    }
  else {
    return (apples/20) + 1;
  }
}


bool SmarterSection(int A_correct, int A_total, int B_correct, int B_total) {

  if (A_correct > A_total) {
    throw std::invalid_argument("");
  }
  else if (B_correct > B_total) {
    throw std::invalid_argument("");
  }
  else if ((A_correct < 0) || (A_total <= 0) || (B_correct < 0) || (B_total <= 0)) {
    throw std::invalid_argument("");
  }
  else {
    double a;
    double b;
    a = (A_correct / double(A_total)) * 100;
    b = (B_correct / double(B_total)) * 100;
    return (a > b);
  }
}



bool GoodDinner(int pizzas, bool is_weekend) {
  if (is_weekend) {
    if (pizzas >= 10) {
      return true;
    }
  }
  else if ((pizzas >= 10) && (pizzas <= 20)) {
    return true;
  }
  return false;
}

int SumBetween(int low, int high) {
  int value = 0;

  if (low > high) {
    throw std::invalid_argument("");
  }

  for (int n = low; n <= high; n++) {
    if (value > INT32_MAX - n) {
      throw std::overflow_error("");
    }
    else if (value < INT32_MIN + n) {
      throw std::overflow_error("");
    }
    
    else if ((low > 0) && (high > 0) && (value < 0)) {
      throw std::overflow_error("");
    }
    else if ((low < 0) && (high < 0) && (value > 0)) {
      throw std::overflow_error("");
    }
    
    else if (low == INT32_MIN && high == INT32_MAX) {
      return INT32_MIN;
    }
    value += n;
  }

  return value;
}

int Product(int a, int b) {

  if ((a > 0) && (b > 0) && (a > INT32_MAX - b)) {
    throw std::overflow_error("");
  }
  else if ((a < 0) && (b < 0) && (a < INT32_MAX - b)) {
    throw std::overflow_error("");
  }
  else {
    return a * b;
  }

}