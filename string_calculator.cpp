// string_calculator.cpp
#include <iostream>
#include "my_string.h"
#include "./string_calculator.h"

using std::cout, std::endl;

unsigned int digit_to_decimal(char digit) {
	int int_digit = 0;
	if (digit >= 48 && digit <= 57) {
		int_digit = digit - 48;
	} else {
		throw std::invalid_argument("");
	}
	
    return int_digit;
}

char decimal_to_digit(unsigned int decimal) {
	char char_decimal = '0';
    if (decimal <= 9) {
		char_decimal = char_decimal + decimal;
	} else {
		throw std::invalid_argument("");
	}
    return char_decimal;
}

my_string trim_leading_zeros(my_string num) {
	
	bool negativeTrim;
	
	if (num.at(0) == '0') {
		int counter = 0;
		unsigned int i = 0;
		while (num[i] == '0') {
			if (i == num.size() - 1) {
				break;
			}
			counter ++;
			i++;
		}
		
		num.erase(0, i);
	} else if (num.at(0) == '-') {
		negativeTrim = true;
		
		num = num.erase(0, 1);
		
		num = trim_leading_zeros(num);
	}
	if (negativeTrim == true && num != "0") {
		num = "-" + num;
	}
    return num;
}

my_string add(my_string lhs, my_string rhs) {
	my_string final_num = "";
	int carry_bit = 0;
	char dig_sum = '0';
	bool doubleNegative = false;
	bool negativeTotal = false;
	
	if (lhs.at(0) == '-' && rhs.at(0) == '-') {
		
		lhs.erase(0,1);
		rhs.erase(0,1);
		
		doubleNegative = true;
		
	}
	if (lhs.at(0) != '-' && rhs.at(0) != '-') {
		lhs = trim_leading_zeros(lhs);
		rhs = trim_leading_zeros(rhs);
		
		lhs = "0" + lhs;
		rhs = "0" + rhs;
		
		int lhs_len = lhs.size();
		int rhs_len = rhs.size();
		
		if (rhs_len > lhs_len) {
			while (rhs_len > lhs_len) {
				lhs = "0" + lhs;
				lhs_len += 1;
			}
		} else if (lhs_len > rhs_len) {
			while (lhs_len > rhs_len) {
				rhs = "0" + rhs;
				rhs_len += 1;
			}
		}
		
		for (int i = lhs_len - 1; i >= 0; i--) {
			dig_sum = carry_bit + (lhs.at(i) + rhs.at(i) - 48);
			if (dig_sum > '9') {
				carry_bit = 1;
				dig_sum = dig_sum - 10;
				final_num = dig_sum + final_num;
			} else {
				carry_bit = 0;
				final_num = dig_sum + final_num;
			}
		}
		
		final_num = trim_leading_zeros(final_num);
		if (doubleNegative == true) {
			final_num = "-" + final_num;
		}
		
	}
	if (lhs.at(0) == '-' && rhs.at(0) != '-') {
		
		lhs = lhs.erase(0, 1);
		lhs = trim_leading_zeros(lhs);
		rhs = trim_leading_zeros(rhs);
		
		lhs = "0" + lhs;
		rhs = "0" + rhs;
		
		int lhs_len = lhs.size();
		int rhs_len = rhs.size();
		
		if (rhs_len > lhs_len) {
			while (rhs_len > lhs_len) {
				lhs = "0" + lhs;
				lhs_len += 1;
			}
			
			for (int i = lhs_len - 1; i >= 0; i--) {
				dig_sum = carry_bit + (rhs.at(i) - lhs.at(i) + 48);
				if (dig_sum < '0') {
					carry_bit = -1;
					dig_sum = dig_sum + 10;
					final_num = dig_sum + final_num;
				} else {
					carry_bit = 0;
					final_num = dig_sum + final_num;
				}
			}
		} else if (lhs_len > rhs_len) {
			while (lhs_len > rhs_len) {
				rhs = "0" + rhs;
				rhs_len += 1;
			}
			
			negativeTotal = true;
			
			for (int i = lhs_len - 1; i >= 0; i--) {
				dig_sum = carry_bit + (lhs.at(i) - rhs.at(i) + 48);
				if (dig_sum < '0') {
					carry_bit = -1;
					dig_sum = dig_sum + 10;
					final_num = dig_sum + final_num;
				} else {
					carry_bit = 0;
					final_num = dig_sum + final_num;
				}
			}
		} else {
			for (int i = 0; i < lhs_len; i++) {
				if (rhs[i] > lhs[i]) {
					break;
				}
				if (lhs[i] > rhs[i]) {
					negativeTotal = true;
					break;
				}
			}
			if (rhs == lhs) {
				final_num = "0";
				return final_num;
			}
			
			if (negativeTotal) {
				for (int i = lhs_len - 1; i >= 0; i--) {
					dig_sum = carry_bit + (lhs.at(i) - rhs.at(i) + 48);
					if (dig_sum < '0') {
						carry_bit = -1;
						dig_sum = dig_sum + 10;
						final_num = dig_sum + final_num;
					} else {
						carry_bit = 0;
						final_num = dig_sum + final_num;
					}
				}
			} else {
				for (int i = lhs_len - 1; i >= 0; i--) {
					dig_sum = carry_bit + (rhs.at(i) - lhs.at(i) + 48);
					if (dig_sum < '0') {
						carry_bit = -1;
						dig_sum = dig_sum + 10;
						final_num = dig_sum + final_num;
					} else {
						carry_bit = 0;
						final_num = dig_sum + final_num;
					}
				}
			}
		}
	} else if (lhs.at(0) != '-' && rhs.at(0) == '-') {
		return add(rhs, lhs);
	}
	final_num = trim_leading_zeros(final_num);
	if (negativeTotal == true) {
		final_num = "-" + final_num;
	}
    return final_num;
}

my_string subtract(my_string lhs, my_string rhs) {
	my_string new_rhs = "";
	
	if (rhs.at(0) == '-') {
		new_rhs = rhs.erase(0, 1);
	} else {
		new_rhs = "-" + rhs;
	}
    
    return add(lhs, new_rhs);
}

my_string multiply(my_string lhs, my_string rhs) {
	
	bool negativeTotal = false;
	my_string final_num = "0";
	
	if (rhs.at(0) == '-' && lhs.at(0) != '-') {
		negativeTotal = true;
		rhs = rhs.erase(0,1);
	}
	if (rhs.at(0) != '-' && lhs.at(0) == '-') {
		negativeTotal = true;
		lhs = lhs.erase(0,1);
	}
	if (rhs.at(0) == '-' && lhs.at(0) == '-') {
		lhs = lhs.erase(0,1);
		rhs = rhs.erase(0,1);
	}
	
	my_string orig_lhs = lhs;
	my_string iterator = "1";
	
	while (rhs.size() >= rhs.size() - 1 && rhs.size() > 1) {
		for (unsigned int i = 0; i < rhs.size() - 1; i++) {
			lhs = lhs + "0";
			iterator = iterator + "0";
		}
		final_num = add(lhs, final_num);
		rhs = subtract(rhs, iterator);
		iterator = "1";
		lhs = orig_lhs;
	}
	while (rhs != "0") {
		final_num = add(lhs, final_num);
		rhs = add(rhs, "-1");
	}
	
	if (negativeTotal == true) {
		final_num = "-" + final_num;
	}
    return final_num;
}