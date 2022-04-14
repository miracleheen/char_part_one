#include <iostream>

void delete_sym(char* sentence, int num, char* ptr_sym) {
	for (int counter = 1; *ptr_sym; counter++) {
		if (counter == num) {
			++ptr_sym;
			continue;
		}
		else {
			*sentence = *ptr_sym;
			++ptr_sym;
			++sentence;
		}
	}
	*sentence = '\0';
}

void delete_all_sym(char* sentence, char sym, char* ptr_sym) {
	while (*ptr_sym) {
		if (*ptr_sym != sym) {
			*sentence = *ptr_sym;
			++sentence;
		}
		++ptr_sym;
	}
	*sentence = '\0';
}

void add_sym(char* sentence, int num, char sym) {
	if (num >= strlen(sentence) + 1 || num < 0) {
		std::cout << "Привет 'sentence'\n";
		return;
	}

	for (int i = strlen(sentence) - 1; i > num; i--)
		sentence[i] = sentence[i - 1];
	sentence[num] = sym;
}

void replace_sym(char* sentence) {
	for (int i = 0; i < strlen(sentence) - 1; i++) {
		if (sentence[i] == ',') sentence[i] = '!';
	}
}

int count_sym(char* sentence, char sym) {
	int32_t amount = 0;
	for (int i = 0; i < strlen(sentence) - 1; i++) {
		if (*(sentence + i) == sym) amount++;
	}
	return amount;
}

void amount_symbols(char* sentence) {
	int32_t amount_letters{ 0 }, amount_numbers{ 0 }, amount_other_sym{ 0 }, i;

	for (i = 0; i < strlen(sentence) - 1; i++) {
		if (isalpha(sentence[i])) amount_letters++;
		else if (isdigit(sentence[i])) amount_numbers++;
		else amount_other_sym++;
	}

	std::cout << "Êîëè÷åñòâî áóêâ:[" << amount_letters << "]" << std::endl;
	std::cout << "Êîëè÷åñòâî öèôð:[" << amount_numbers << "]" << std::endl;
	std::cout << "Êîëè÷åñòâî îñòàëüíûõ ñèìâîëîâ:[" << amount_other_sym << "]" << std::endl;
}


int main() {
	setlocale(LC_ALL, "ru");

	int32_t choice, number;
	char sym;

	char sentence[] = "Life is a sum of all your choices.So,,what are you doing today?\n"
		"Albert Camus(1913–1960)\n";

	std::cout << sentence << '\n';
	char* ptr_sym = sentence;

	std::cout << "[1] Óäàëèòü èç ñòðîêè ñèìâîë ñ çàäàííûì íîìåðîì;" << '\n';
	std::cout << "[2] Óäàëèòü èç ñòðîêè âñå âõîæäåíèÿ â íåå çàäàííîãî ñèìâîëà;" << '\n';
	std::cout << "[3] Âñòàâèòü â ñòðîêó â óêàçàííóþ ïîçèöèþ çàäàííûé ñèìâîë;" << '\n';
	std::cout << "[4] Çàìåíèòü âñå ñèìâîëû çàïÿòîé â ñòðîêå, íà ñèìâîëû âîñêëèöàòåëüíîãî çíàêà;" << '\n';
	std::cout << "[5] Ïîñ÷èòàòü ñêîëüêî ðàç ââåäåíûé ñèìâîë âñòðå÷àåòñÿ â ñòðîê;" << '\n';
	std::cout << "[6] Îïðåäåëèòü êîëè÷åñòâî áóêâ, êîëè÷åñòâî öèôð è êîëè÷åñòâî îñòàëüíûõ ñèìâîëîâ, ïðèñóòñòâóþùèõ â ñòðîêå." << "\n\n";
	std::cout << "Ââåäèòå íîìåð ìåíþ:";
	std::cin >> choice;

	switch (choice) {
	case 1: std::cout << "Ââåäèòå íîìåð ñèìâîëà: "; std::cin >> number; std::cout << '\n';
		delete_sym(sentence, number, ptr_sym);

		std::cout << std::endl;
		std::cout << "Èçìåíåííàÿ ñòðîêà: " << sentence << "\n\n";
		break;

	case 2: std::cout << "Ââåäèòå ñèìâîë: "; std::cin >> sym;
		delete_all_sym(sentence, sym, ptr_sym);

		std::cout << std::endl;
		std::cout << "Èçìåíåííàÿ ñòðîêà: " << sentence << "\n\n";
		break;

	case 3: std::cout << "Ââåäèòå ïîçèöèþ äëÿ âñòàâêè: "; std::cin >> number;
		std::cout << "Ââåäèòå ñèìâîë äëÿ äîáàâëåíèÿ â óêàçàííóþ ïîçèöèþ: "; std::cin >> sym; std::cout << '\n';
		add_sym(sentence, number, sym);

		std::cout << std::endl;
		std::cout << "Èçìåíåííàÿ ñòðîêà: " << sentence << "\n\n";
		break;

	case 4: replace_sym(sentence); std::cout << std::endl;
		std::cout << "Èçìåíåííàÿ ñòðîêà: " << sentence << "\n\n";
		break;

	case 5: std::cout << "Ââåäèòå ñèìâîë: "; std::cin >> sym; std::cout << std::endl;
		std::cout << "Âñåãî ñèìâîëîâ '" << sym << "': " << count_sym(sentence, sym) << std::endl;
		break;

	case 6: std::cout << std::endl; amount_symbols(sentence);
		break;
	}

	return 0;
}
