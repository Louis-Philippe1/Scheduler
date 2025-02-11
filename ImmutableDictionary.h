class ImmutableDictionary {
private:
    const std::map<int, std::string> data;
    
    // Private constructor that initializes the map
    ImmutableDictionary();
    
    // Helper method to initialize the data
    static std::map<int, std::string> initializeData();

public:
    // Delete copy constructor and assignment operator to ensure immutability
    ImmutableDictionary(const ImmutableDictionary&) = delete;
    ImmutableDictionary& operator=(const ImmutableDictionary&) = delete;

    // Singleton pattern to ensure only one instance exists
    static const ImmutableDictionary& getInstance();

    // Lookup value by key
    std::string get(int key) const;

    // Check if key exists
    bool contains(int key) const;

    // Get size of dictionary
    size_t size() const;

    // Print all entries
    void printAll() const;
};

#endif // IMMUTABLE_DICTIONARY_H
