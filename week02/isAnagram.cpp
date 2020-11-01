bool isAnagram(string s, string t) {
	if (s.size() != t.size()) return false;


	vector<int>bins(256, 0);
	for (int i = 0;i < s.size();i++) {
		bins[s[i]]++;
	}
	int match = t.size();
	for (int j = 0;j < t.size();j++) {
		if (bins[t[j]] == 0)
			return false;
		else {
			bins[t[j]]--;
			match--;
		}
	}
	if (match == 0) return true;
	else
		return false;
}