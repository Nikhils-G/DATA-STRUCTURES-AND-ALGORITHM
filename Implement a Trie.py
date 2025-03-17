class TrieNode:
    def __init__(self):
        self.children = {}  # Dictionary to store child nodes
        self.is_end_of_word = False  # Marks the end of a word

class Trie:
    def __init__(self):
        self.root = TrieNode()  # Root node of the Trie

    def insert(self, word: str) -> None:
        """
        Inserts a word into the Trie.
        """
        current_node = self.root
        for char in word:
            if char not in current_node.children:
                current_node.children[char] = TrieNode()  # Create a new node if the character doesn't exist
            current_node = current_node.children[char]  # Move to the next node
        current_node.is_end_of_word = True  # Mark the end of the word

    def search(self, word: str) -> bool:
        """
        Returns True if the word is in the Trie, otherwise False.
        """
        current_node = self.root
        for char in word:
            if char not in current_node.children:
                return False  # Character not found
            current_node = current_node.children[char]  # Move to the next node
        return current_node.is_end_of_word  # Check if it's the end of a word

    def starts_with(self, prefix: str) -> bool:
        """
        Returns True if there is any word in the Trie that starts with the given prefix.
        """
        current_node = self.root
        for char in prefix:
            if char not in current_node.children:
                return False  # Prefix not found
            current_node = current_node.children[char]  # Move to the next node
        return True  # Prefix exists

    def delete(self, word: str) -> bool:
        """
        Deletes a word from the Trie if it exists.
        Returns True if the word was deleted, otherwise False.
        """
        def _delete_helper(node, word, depth):
            if depth == len(word):
                if not node.is_end_of_word:
                    return False  # Word doesn't exist in the Trie
                node.is_end_of_word = False  # Unmark the end of the word
                return len(node.children) == 0  # Return True if no children
            char = word[depth]
            if char not in node.children:
                return False  # Word doesn't exist in the Trie
            should_delete_current_node = _delete_helper(node.children[char], word, depth + 1)
            if should_delete_current_node:
                del node.children[char]  # Delete the node if it has no children
                return len(node.children) == 0  # Return True if no children left
            return False

        return _delete_helper(self.root, word, 0)

    def print_trie(self):
        """
        Utility function to print the Trie structure.
        """
        def _print_helper(node, prefix):
            if node.is_end_of_word:
                print(prefix)
            for char, child_node in node.children.items():
                _print_helper(child_node, prefix + char)

        _print_helper(self.root, "")


# Example Usage
if __name__ == "__main__":
    trie = Trie()
    trie.insert("apple")
    trie.insert("app")
    trie.insert("banana")
    trie.insert("bat")
    trie.insert("batch")

    print("Trie after insertion:")
    trie.print_trie()

    print("\nSearch operations:")
    print("Search 'apple':", trie.search("apple"))  # True
    print("Search 'app':", trie.search("app"))  # True
    print("Search 'appl':", trie.search("appl"))  # False

    print("\nStarts with operations:")
    print("Starts with 'ban':", trie.starts_with("ban"))  # True
    print("Starts with 'batc':", trie.starts_with("batc"))  # True
    print("Starts with 'batx':", trie.starts_with("batx"))  # False

    print("\nDelete operations:")
    print("Delete 'app':", trie.delete("app"))  # True
    print("Delete 'apple':", trie.delete("apple"))  # True
    print("Delete 'bat':", trie.delete("bat"))  # True

    print("\nTrie after deletion:")
    trie.print_trie()
