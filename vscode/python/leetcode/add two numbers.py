def combine_and_add_lists(list1, list2):
    # Combine the numbers from both lists in reverse order
    combined_reverse = int(''.join(map(str, list1[::-1]))) + int(''.join(map(str, list2[::-1])))

    # Combine the numbers from both lists in normal order
    combined_normal = int(''.join(map(str, list1))) + int(''.join(map(str, list2)))

    # Convert the result back to a list and reverse it
    combined_reverse_list = [int(digit) for digit in str(combined_reverse)][::-1]

    return combined_reverse_list


def main():
    # Input two lists from the user
    list1 = [int(x) for x in input("Enter the first list of numbers separated by space: ").split()]
    list2 = [int(x) for x in input("Enter the second list of numbers separated by space: ").split()]

    # Calculate and print the result
    result_list = combine_and_add_lists(list1, list2)
    print("Combined and added list:", result_list)


if __name__ == "__main__":
    main()
