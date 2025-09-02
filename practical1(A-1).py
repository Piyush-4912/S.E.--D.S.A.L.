#Consider telephone book database of N clients. Make use of a hash table implementation to quickly look up client‘s
#telephone number. Make use of two collision handling techniques and compare them using number of comparisons required to
#find a set of telephone numbers

# Function to get phone numbers from user
def tele_database():
    phone_data = []
    n = int(input("Enter number of clients: "))
    print("Enter phone numbers:\n")
    for _ in range(n):
        x = int(input("--> "))
        phone_data.append(x)
    return phone_data

# Primary hash function (modulo-based)
def hash_function_1(key_ele, m_size):
    return key_ele % m_size

# Secondary hash function used for double hashing
def hash_function_2(key_ele):
    return 1 + (key_ele % 11)  # Ensures step size is not 0

# Function to display the hash table
def display_hashtable(ht):
    print("\nHash Index\tKey")
    for index, value in enumerate(ht):
        if value != -1:
            print(f"{index}\t\t--->\t{value}")
        else:
            print(f"{index}\t\t--->\tEmpty")

# Main code execution starts here
if __name__ == "__main__":
    phone_database = tele_database()  # Get the list of phone numbers

    m = int(input("\nEnter hash table size: "))
    hash_table = [-1] * m  # Initialize hash table with -1 (indicating empty slots)

    # Ask user to choose collision resolution method
    opt = int(input(
        "\nIf collision occurs, which collision resolution technique do you want to use?\n"
        "\t1. Linear Probing\n"
        "\t2. Double Hashing\n"
        "Enter option (1 or 2): "
    ))

    # Inserting elements into hash table
    for key in phone_database:
        h1 = hash_function_1(key, m)

        if hash_table[h1] == -1:
            # If no collision, place directly
            hash_table[h1] = key
        else:
            # Collision handling
            if opt == 1:
                # Linear Probing
                original_h1 = h1
                while hash_table[h1] != -1:
                    h1 = (h1 + 1) % m
                    if h1 == original_h1:
                        print("Hash table is full, can't insert more elements.")
                        break
                else:
                    hash_table[h1] = key

            elif opt == 2:
                # Double Hashing
                h2 = hash_function_2(key)
                i = 1
                new_index = h1
                while hash_table[new_index] != -1:
                    new_index = (h1 + i * h2) % m
                    i += 1
                    if i > m:
                        print("Hash table is full, can't insert more elements.")
                        break
                else:
                    hash_table[new_index] = key

            else:
                print("Invalid option selected. Please restart the program.")
                break

    # Display the final hash table
    display_hashtable(hash_table)
