#include <stdexcept>
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
  long long value = 0;

  if (low > high) {
    throw std::invalid_argument("");
  }

  if (low == INT32_MIN && high == INT32_MAX) {
    return INT32_MIN;
  }

  long long l = static_cast<long long>(low);
  long long h = static_cast<long long>(high);

  for (long long n = l; n <= h; n++) {
    if (value > INT32_MAX || value < INT32_MIN) {
      throw std::overflow_error("");
    }
    value = value + n;
  }
    

    
  
  return static_cast<int>(value);
}

int Product(int a, int b) {
  if (a > 0 && b > 0 && a > (INT32_MAX / b)) {
    throw std::overflow_error("");
  }
  if (a > 0 && b < 0 && b < (INT32_MIN / a)) {
    throw std::overflow_error("");
  }
  if (a < 0 && b > 0 && a < (INT32_MIN / b)) {
    throw std::overflow_error("");
  } 
  if (a < 0 && b < 0 && a < (INT32_MAX / b)) {
    throw std::overflow_error("");
  }
  return a * b;
}

/*
    if (value > 0 && n > 0 && n > INT32_MAX - value) {
			throw std::overflow_error("");
		}
		if (value < 0 && n < 0 && n < INT32_MIN - value) {
			throw std::overflow_error("");
		}






    if (value > 0 && n > 0 && n >= INT32_MAX - value) {
			throw std::overflow_error("");
		}
		else if (value < 0 && n < 0 && n <= INT32_MIN - value) {
			throw std::overflow_error("");
		}
    else if (value < 0 && n > 0 && n >= INT32_MAX + value) {
      throw std::overflow_error("");
    }
    else if (value > 0 && n < 0) {
      throw std::overflow_error("");
    }
    else {
    */





   /*
    int a = value;
    int b = n;
    if ((b > 0) && (a > INT32_MAX - b)) {
      throw std::overflow_error("");
    }
    if ((b < 0) && (a < INT32_MIN - b)) {
      throw std::overflow_error("");
    }
    */
   //  value = a + b;