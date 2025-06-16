# hashing values based on predefined functions and storing similar values in same bucket
# for search buckets are searched instead of entire array
# time complexity for search is O(1)

# for a hash table with 10 buckets
# a hash function returns a hash value that represents the original value
def hash_function(value):
    return sum(ord(v) for v in value) % 10

# add hash value to it's bucket
# hash sets store only unique values
def add(hash_set, value):
    hash_value = hash_function(value)
    bucket = hash_set[hash_value]
    
    if value not in bucket:
        bucket.append(value)

hash_set = [[] for _ in range(10)]


# hash set is a hash table that stores unique values
# this example generates hash using unicode sum of characters in string
class hashSet:
    def __init__(self, size):
        self.size = size
        self.buckets = [[] for _ in range(size)]

    def hash_function(self, value):
        return sum(ord(v) for v in value) % self.size
    
    def add(self, value):
        index = self.hash_function(value)
        bucket = self.buckets[index]
        if value not in bucket:
            bucket.append(value)

    def contains(self, value):
        index = self.hash_function(value)
        return value in self.buckets[index]
    
    def remove(self, value):
        index = self.hash_function(value)
        bucket = self.buckets[index]
        if value in bucket:
            bucket.remove(value)

    def print_set(self):
        print("All buckets:")
        for i, bucket in enumerate(self.buckets):
            print(i, bucket)


# -------------------------HASH MAP--------------------------------
# hash map is a hash table that stores key value pair
# hash is generated using unique key, bucket is determined using hash
# values are stored in buckets along with key

# this example generates hash using social security number
class hashMap:
    def __init__(self, size=100) -> None:
        self.size = size
        self.buckets = [[] for _ in range(size)]

    def hash_function(self, key):
        # Sum only the numerical values of the key
        return sum(int(k) for k in key if k.isdigit()) % self.size
    
    def add(self, key, value):
        index = self.hash_function(key)
        bucket = self.buckets[index]
        
        for i, (k, v) in enumerate(bucket):
            if k == key:
                bucket[i] = (key, value)
                return
        bucket.append((key, value))

    def get(self, key):
        index = self.hash_function(key)
        bucket = self.buckets[index]
        
        for k, v in bucket:
            if k == key:
                return v
        return None
    
    def remove(self, key):
        index = self.hash_function(key)
        bucket = self.buckets[index]
        
        for i, (k, v) in enumerate(bucket):
            if k == key:
                del bucket[i]
                return
    
    def print_map(self):
        for i, bucket in enumerate(self.buckets):
            print(f"Bucket {i}: {bucket}")
            
