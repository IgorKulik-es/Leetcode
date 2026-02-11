#include <iostream>
#include <string>
#include <vector>

typedef std::vector<std::string> WordSet;
typedef std::vector<WordSet> WordPage;

class Trie {
	private:
		Trie*	nextNodes[26] = {};
		bool	isWordEnd = false;
	public:
		Trie*		StepForward(Trie* root, char c);
		WordSet&	FindNextWords(Trie* iterTrie, WordSet& wordSet, std::string& readWord, size_t numWords);
		static void	CleanChildren(Trie* iterTrie);
		void		insert(std::string word);
		Trie();
};

Trie::Trie(){};

void Trie::insert(std::string word)
{
	std::string::iterator	iterWord = word.begin();
	std::string::iterator	iterEndWord = word.end();
	Trie*					iterNode = this;
	int						indexLetter;

	while (iterWord != iterEndWord)
	{
		indexLetter = *iterWord - 'a';
		if (iterNode->nextNodes[indexLetter] == NULL)
			iterNode->nextNodes[indexLetter] = new Trie();
		iterNode = iterNode->nextNodes[indexLetter];
		iterWord++;
	}
	iterNode->isWordEnd = true;
}

Trie*	Trie::StepForward(Trie* root, char c)
{
	return root->nextNodes[c - 'a'];
}

void	Trie::CleanChildren(Trie* iterTrie)
{
	for (int i = 0; i < 26; i++)
	{
		if (iterTrie->nextNodes[i] != nullptr)
		{
			CleanChildren(iterTrie->nextNodes[i]);
			delete iterTrie->nextNodes[i];
		}
	}
}

class Solution
{
	private:
	public:
		Trie	dictionary;
		WordPage suggestedProducts(WordSet& products, std::string searchWord);
};

WordPage	Solution::suggestedProducts(WordSet& products, std::string searchWord)
{
	WordPage	suggestions(searchWord.length(), WordSet(0, ""));
	std::string	nextWord("");
	Trie*		iterTrie = &dictionary;
	int			wordLength = searchWord.length();

	for (std::string& product: products)
		dictionary.insert(product);
	for (int i = 0; i < wordLength; i++)
	{
		iterTrie = dictionary.StepForward(iterTrie, searchWord[i]);
		if (iterTrie == nullptr)
			break;
		nextWord.push_back(searchWord[i]);
		dictionary.FindNextWords(iterTrie, suggestions[i], nextWord, 3);
	}
	dictionary.CleanChildren(&dictionary);
	return suggestions;
}

WordSet&	Trie::FindNextWords(Trie* iterTrie, WordSet& wordSet, std::string& readWord, size_t numWords)
{
	if (wordSet.size() == numWords)
		return wordSet;
	if (iterTrie->isWordEnd)
		wordSet.push_back(readWord);
	for (int i = 0; i < 26 && wordSet.size() < numWords; i++)
	{
		if (iterTrie->nextNodes[i] != nullptr)
		{
			readWord.push_back(i + 'a');
			FindNextWords(iterTrie->nextNodes[i], wordSet, readWord, numWords);
			readWord.pop_back();
		}
	}
	return wordSet;
}

template <class T>
void	PrintVector(std::vector<T>	vec)
{
	for (size_t i = 0; i < vec.size(); i++)
		std::cout << vec[i] << " ";
	std::cout << std::endl;
}

void	PrintPage(WordPage& page)
{
	for (size_t i = 0; i < page.size(); i++)
		PrintVector(page[i]);
}

int main()
{
	{
		std::cout << "test 1:\n";
		Solution	solve;
		WordSet		products({"mobile","mouse","moneypot","monitor","mousepad"});
		std::string	find("mouse");
		WordPage	page;
		page = solve.suggestedProducts(products, find);
		PrintPage(page);
	}
	{
		std::cout << "test 2:\n";
		Solution	solve;
		WordSet		products({"havana"});
		std::string	find("havana");
		WordPage	page;
		page = solve.suggestedProducts(products, find);
		PrintPage(page);
	}
	{
		std::cout << "test 3:\n";
		Solution	solve;
		WordSet		products({"havana"});
		std::string	find("havqq");
		WordPage	page;
		page = solve.suggestedProducts(products, find);
		PrintPage(page);
	}
	{
		std::cout << "test 4:\n";
		Solution	solve;
		WordSet		products({"aaa", "aa", "ab", "abb"});
		std::string	find("aaaa");
		WordPage	page;
		page = solve.suggestedProducts(products, find);
		PrintPage(page);
	}
	return 0;
}
