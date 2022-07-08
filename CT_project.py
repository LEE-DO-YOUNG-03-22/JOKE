food_list = ["볶음밥 : 4000원","덮밥 : 4000원"]
snack_list = ["과자 : 1500원","핫도그 : 3500원","음료수 : 1500원"]
time_list = ["1시간 : 1000원","2시간 : 2000원","5시간 : 5000원","10시간 : 10000원"]
food_money_list = [4000,4000]
snack_money_list = [1500,3500,1500]
time_money_list = [1000,2000,5000,10000]
shopping_basket = []

def main():
    time = int(input("남은 시간을 입력하세요. : "))
    money = int(input("예산을 입력하세요. : "))
    type = input("시간, 음식 중 주문 하실 항목을 고르세요. : ")
    if(type == "시간"):
        TIME()
    elif(type == "음식"):
        FOOD()
    else:
        print("잘못 입력하셨습니다. 초기화면으로 돌아갑니다...")
        main()

def PAYMENT(Y_N):
    if(Y_N == 'Y' or 'y'):
        print("결제창으로 넘어갑니다...")
        return
    elif(Y_N == 'N' or 'n'):
        print("초기화면으로 돌아갑니다...")
        return

def TIME():
    print(time_list)
    time_choice = int(input("몇시간 충전 하실건가요?(ex. 1번 -> 1 입력)[돌아가기 : 0] : "))
    if(time_choice == 0):
        return
    elif(time_choice > 0):
        time_choice = time_choice - 1
        shopping_basket.append(time_money_list[time_choice])
        print(shopping_basket)
        print(time_list[time_choice], end = '')
        Y_N = input("을 결제하실건가요? : ")
        PAYMENT(Y_N)
    else:
        print("잘못 입력하셨습니다. 되돌아갑니다...")
        TIME()

def FOOD():
    type_choice = input("식사와 간식종류중 고르시오. : ")
    if(type_choice == "식사"):
        print(food_list)
        food_choice = int(input("어떤 음식을 드실껀가요?(ex. 1번 -> 1 입력)[돌아가기 : 0] : "))
        if(food_choice == 0):
            return
        elif(food_choice > 0):
            food_choice = food_choice - 1
            shopping_basket.append(food_money_list[food_choice])
            print(shopping_basket)
            print(food_list[food_choice],end= '')
            food_num = int(input("갯수를 입력하세요. : "))
            Y_N = input("을 결제하실건가요? : ")
    elif(type_choice == "간식"):
        print(snack_list)
        snack_choice = int(input("어떤 간식을 드실껀가요?(ex. 1번 -> 1 입력)[돌아가기 : 0]"))
        if(snack_choice == 0):
            return
        elif(snack_choice > 0):
            snack_choice = snack_choice - 1
            shopping_basket.append(snack_money_list[snack_choice])
            print(shopping_basket)
            print(snack_list[snack_choice],end= '')
            food_num = int(input("갯수를 입력하세요. : "))
            Y_N = input("을 결제하실건가요? : ")
    else:
        print("잘못 입력하셨습니다. 되돌아갑니다...")
        FOOD()

main()
