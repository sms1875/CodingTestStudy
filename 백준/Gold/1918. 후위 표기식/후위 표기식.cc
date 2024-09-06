#include <iostream>
#include <stack>
#include <vector>
#include <string>

using namespace std;

int precedence(char op) {
	if (op == '^') return 3;
	if (op == '*' || op == '/') return 2;
	if (op == '+' || op == '-') return 1;
	return 0;
}

vector<string> shuntingYard(const string& str) {
	stack<char> operators;
	vector<string> output;
	string token = "";

	// 문자열을 순차적으로 읽어서 토큰화
	for (size_t i = 0; i < str.size(); i++) {
		char current = str[i];

		// 여는 괄호는 스택에 추가
		if (current == '(') {
			operators.push(current);
		}
		// 닫는 괄호는 여는 괄호를 만날 때까지 스택에서 연산자를 출력
		else if (current == ')') {
			while (!operators.empty() && operators.top() != '(') {
				output.push_back(string(1, operators.top()));
				operators.pop();
			}
			operators.pop(); // 여는 괄호 제거
		}
		// 피연산자 확인
		else if (precedence(current)==0) {
			token += current;
			output.push_back(token); 
			token = "";
		}
		// 연산자 처리
		else {
			while (!operators.empty() &&
				(precedence(operators.top()) > precedence(current) ||(precedence(operators.top()) == precedence(current)))) {output.push_back(string(1, operators.top()));
				operators.pop();
			}
			operators.push(current);
		}
	}

	// 스택에 남은 연산자 모두 출력
	while (!operators.empty()) {
		output.push_back(string(1, operators.top()));
		operators.pop();
	}

	return output;
}

int main() {
	string str; 
	cin >> str;

	vector<string> result = shuntingYard(str);

	for (const string& token : result) {
		cout << token ;
	}
	cout << endl;

	return 0;
}
