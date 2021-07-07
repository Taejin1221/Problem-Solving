class Solution {
	public boolean isPalindome(int x) {
		if (x < 0) return false;

		int reverseNum = 0;
		int quotient = x;

		while (quotient != 0) {
			int unit = quotient % 10;

			// Check Overflow
			if (Integer.MAX_VALUE / 10 < reverseNum) return false;
			else if (Integer.MAX_VALUE / 10 == reverseNum) {
				if (Integer.MAX_VALUE % 10 < unit) return false;
			} else {
				reverseNum *= 10;
				reverseNum += unit;
				quotient /= 10;
			}
		}

		if (reverseNum == x) return true;
		else return false;
	}
}