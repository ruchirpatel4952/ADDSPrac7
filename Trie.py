class TrieNode:
    def __init__(self):
        self.children = {}  # Dictionary to store child nodes
        self.isEndOfWord = False  # Flag to check if node marks the end of a word

class Autocomplete:
    def __init__(self):
        self.root = TrieNode()  # Root of the Trie

    def insert(self, word):
        # Insert a word into the Trie
        current = self.root
        for char in word:
            if char not in current.children:
                current.children[char] = TrieNode()
            current = current.children[char]
        current.isEndOfWord = True  # Mark the end of the word

    def getSuggestions(self, partialWord):
        # Get all words starting with the prefix 'partialWord'
        current = self.root
        for char in partialWord:
            if char not in current.children:
                return []  # No suggestions if prefix not in Trie
            current = current.children[char]
        
        # Now we are at the end of the partialWord, find all words starting from this point
        suggestions = []
        self._findWordsFromNode(current, partialWord, suggestions)
        return suggestions

    def _findWordsFromNode(self, node, prefix, suggestions):
        # Helper function to recursively find all words starting from the given node
        if node.isEndOfWord:
            suggestions.append(prefix)  # Add word to the suggestion list
        for char, childNode in node.children.items():
            self._findWordsFromNode(childNode, prefix + char, suggestions)  # Recursively find more words

# Example usage:
autocomplete = Autocomplete()

# Insert words into the Autocomplete system
autocomplete.insert("bin")
autocomplete.insert("ball")
autocomplete.insert("ballet")

# Test the getSuggestions function
print(autocomplete.getSuggestions("b"))     # Output: ['bin', 'ball', 'ballet']
print(autocomplete.getSuggestions("ba"))    # Output: ['ball', 'ballet']
print(autocomplete.getSuggestions("bal"))   # Output: ['ball', 'ballet']
print(autocomplete.getSuggestions("balle")) # Output: ['ballet']
