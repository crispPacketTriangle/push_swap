import random as r
import os
import time


def main():

    for i in range(30):

        nums = []
        str_input = ""
        n = r.randint(3, 500)
        nums = r.sample(range(-300, 300), n)

        for i in range(len(nums)):
            str_input += str(nums[i])
            str_input += " "
#        print(n)
        os.system(f'./push_swap {str_input} | ./checker_linux {str_input}')
        print("----------")
        time.sleep(2)


if __name__ == "__main__":
    main()
