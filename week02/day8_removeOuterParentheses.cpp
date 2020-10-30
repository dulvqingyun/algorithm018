string removeOuterParentheses(string S) {
	string res;
	//记录有效括号
	stack<char> stack;
	//i遍历 j下次操作开始位置
	for (int i = 0, j = 0;i < S.size();i++) {
		if (S[i] == '(') 
			stack.push('(');
		else 
			stack.pop();
		if (stack.size() == 0) {
			
			res += S.substr(j + 1, i - j - 1);
			j = i + 1;

		}
			 
	}
	return res;
}