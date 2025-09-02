#To create ADT that implement the "set" concept. a. Add (new Element) -Place a value into the set , b. Remove
#(element) Remove the value c. Contains (element) Return true if element is in collection, d. Size () Return number of values in
#collection Iterator () Return an iterator used to loop over collection, e. Intersection of two sets , f. Union of two sets, g. Difference
#between two sets, h. Subset
# Initialize two sets
s1 = set()
s2 = set()

# Function to create a set
def create(s):
    n = int(input("Enter the number of elements in the set: "))
    for i in range(n):
        e = int(input(f"Enter element {i + 1}: "))
        s.add(e)
    print("Set after creation:", s)

# Function to add an element to a set
def add(s):
    e = int(input("Enter the element to add: "))
    s.add(e)
    print("Set after addition:", s)

# Function to remove an element from a set
def remove(s):
    e = int(input("Enter the element to remove: "))
    if e in s:
        s.remove(e)
        print("Set after removal:", s)
    else:
        print("Element not found in the set.")

# Function to search an element in a set
def search(s):
    e = int(input("Enter the element to search: "))
    if e in s:
        print("Element is present in the set.")
    else:
        print("Element is not present in the set.")

# Function to print size of both sets
def size():
    print(f"Size of Set A: {len(s1)}")
    print(f"Size of Set B: {len(s2)}")

# Function to print intersection of s1 and s2
def intersection():
    result = s1.intersection(s2)
    print("Intersection of Set A and Set B:", result)

# Function to print union of s1 and s2
def union():
    result = s1.union(s2)
    print("Union of Set A and Set B:", result)

# Function to print difference s1 - s2
def difference():
    result = s1.difference(s2)
    print("Difference (Set A - Set B):", result)

# Function to check if s2 is subset of s1
def subset():
    if s2.issubset(s1):
        print("Set B is a subset of Set A.")
    else:
        print("Set B is not a subset of Set A.")

# Menu-driven program
def main():
    while True:
        print("\n" + "*" * 25 + " MENU " + "*" * 25)
        print("1. Create Sets")
        print("2. Add an Element")
        print("3. Remove an Element")
        print("4. Search for an Element")
        print("5. Find the Size of Sets")
        print("6. Intersection of Sets")
        print("7. Union of Sets")
        print("8. Difference of Sets (A - B)")
        print("9. Check Subset")
        print("10. EXIT")
        
        try:
            choice = int(input("Enter your choice (1-10): "))
        except ValueError:
            print("Please enter a valid integer.")
            continue

        if choice == 1:
            print("\n--- Creating Set A ---")
            create(s1)
            print("\n--- Creating Set B ---")
            create(s2)
        elif choice == 2:
            print("\n1. Add to Set A")
            print("2. Add to Set B")
            sub_choice = int(input("Enter your choice: "))
            if sub_choice == 1:
                add(s1)
            elif sub_choice == 2:
                add(s2)
            else:
                print("Invalid option.")
        elif choice == 3:
            print("\n1. Remove from Set A")
            print("2. Remove from Set B")
            sub_choice = int(input("Enter your choice: "))
            if sub_choice == 1:
                remove(s1)
            elif sub_choice == 2:
                remove(s2)
            else:
                print("Invalid option.")
        elif choice == 4:
            print("\n1. Search in Set A")
            print("2. Search in Set B")
            sub_choice = int(input("Enter your choice: "))
            if sub_choice == 1:
                search(s1)
            elif sub_choice == 2:
                search(s2)
            else:
                print("Invalid option.")
        elif choice == 5:
            size()
        elif choice == 6:
            intersection()
        elif choice == 7:
            union()
        elif choice == 8:
            difference()
        elif choice == 9:
            subset()
        elif choice == 10:
            print("Exiting program. Goodbye!")
            break
        else:
            print("Invalid choice. Please enter a number between 1 and 10.")

# Execute main function
if __name__ == "__main__":
    main()
