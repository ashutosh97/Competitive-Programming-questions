def is_isogram(string):
    lower_string = string.lower()
    unique_string = set(lower_string)
    return (len(lower_string)==len(unique_string))

def main():
    print(is_isogram("Dermatoglyphics"))
    print(is_isogram("aba"))
    print(is_isogram("moOse"))
    print(is_isogram(""))

main()