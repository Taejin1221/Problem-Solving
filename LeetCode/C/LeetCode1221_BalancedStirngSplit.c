/* Prob1221_BalancedStringSplit */
int balancedStringSplit(char * s) {
	int split = 0;
	int timesR = 0, timesL = 0;

	for (int idx = 0; s[idx]; idx++) {
		s[idx] == 'R' ? timesR++ : timesL++;

		if (timesR == timesL) {
			split++;
			timesR = timesL = 0;
		}
	}

	return split;
}