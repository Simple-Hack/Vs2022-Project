#include<iostream>
#include<string>
#include<vector>
#include <numeric>
class Solution {
public:
	std::vector<int> CountNullNums(std::string s) {
		int length = s.size();
		std::vector<int> count;
		int num = 0;
		for (int i = 0; i < length; i++) {
			if (s[i] != ' ') {
				num++;
			}
			else {
				count.push_back(num);
				num = 0;
			}
		}
		if (num != 0) count.push_back(num);
		return count;
	}
	std::vector<std::string> fullJustify(std::vector<std::string>& words, int maxWidth) {
		std::vector<std::string> ans;
		int lengthWords = words.size();
		int ind = 0;
		while (ind < lengthWords) {
			std::string res = "";
			int nextZone = maxWidth - words[ind].size();
			res += words[ind];
			while (nextZone > 0) {
				if (ind + 1 < lengthWords && nextZone >= words[ind + 1].size() + 1) {
					nextZone -= words[ind + 1].size() + 1;
					res +=" "+ words[++ind];
				}
				else if (ind + 1 < lengthWords && nextZone < words[ind + 1].size() + 1) {
					std::vector<int> count = CountNullNums(res);
					std::string trueRes = "";
					int nullNum = count.size() - 1;
					//int countNull = 0;
					int spaceNum, addNum;

					if (nullNum > 0) {
						spaceNum = (maxWidth - std::accumulate(count.begin(), count.end(), 0)) / nullNum;
						addNum = (maxWidth - std::accumulate(count.begin(), count.end(), 0)) % nullNum;
					}
					else {
						spaceNum = addNum = 0;

					}
					for (int i = 0; i < res.size(); i++) {
						if (res[i] != ' ') {
							trueRes += res[i];
						}
						else {
							int num = spaceNum;
							while (num-- > 0) trueRes += " ";
							if (addNum > 0) {
								trueRes += " ";
								addNum -= 1;
							}
						}
					}
					while (trueRes.size() < maxWidth) {
						trueRes += " ";
					}
					nextZone = 0;
					res = trueRes;
				}
				else if (ind + 1 >= lengthWords) {
					int temp = maxWidth - res.size();
					if (res.size() != maxWidth) {
						while (temp-- > 0) {
							res += " ";
						}
					}
					nextZone = 0;
				}
			}
			ind += 1;
			ans.push_back(res);
		}
		return ans;
	}
};

int main() {
	Solution s;
	std::vector<std::string> words = { "Science","is","what","we","understand","well","enough","to","explain","to","a","computer.","Art","is","everything","else","we","do" };
	int maxWidth = 20;
	for (auto data : s.fullJustify(words, maxWidth)) {
		std::cout << data << std::endl;
	}
}