science = ["나중부피구하는함수_보일","나중압력구하는함수_보일","나중부피구하는함수_샤를","나중온도구하는함수_샤를","기체의분자량_질량을아는경우","기체의분자량_밀도를아는경우","퍼센트농도구하는함수","PPM농도구하는함수","몰랄농도구하는함수","몰농도구하는함수","퍼센트농도로몰농도구하는함수","퍼센트농도로몰랄농도구하는함수","몰농도로몰랄농도구하는함수"]

def 나중부피구하는함수():
    P1=float(input("처음 압력(atm)을 입력하시오. : "))
    P2=float(input("나중 압력(atm)을 입력하시오. : "))
    V1=float(input("처음 부피(L)를 입력하시오. : "))

    V2=(P1*V1)/P2

    print("----------------------------------------------")
    print("이 기체의 나중부피는" , round(V2, 3) , "L 입니다.")
    print("----------------------------------------------")

def 나중압력구하는함수():
    P1=float(input("처음 압력(atm)을 입력하시오. : "))
    V1=float(input("처음 부피(L)를 입력하시오. : "))
    V2=float(input("나중 부피(L)을 입력하시오. : "))

    P2=(P1*V1)/V2

    print("----------------------------------------------")
    print("이 기체의 나중기압은" , round(P2, 3) , "atm 입니다.") 
    print("----------------------------------------------")

def 나중부피구하는함수_샤를() : 
    T1=float(input("처음 온도(°C)를 입력하시오. : "))
    T2=float(input("나중 온도(°C)를 입력하시오. : "))
    V1=float(input("처음 부피를 입력하시오. : "))

    V2=((T2+273)*V1)/(T1+273)

    print("----------------------------------------------")
    print("이 기체의 나중부피는", round(V2, 3) , "L 입니다.")
    print("----------------------------------------------")

def 나중온도구하는함수_샤를() : 
    T1=float(input("처음 온도(°C)를 입력하시오. : "))
    V1=float(input("처음 부피를 입력하시오. : "))
    V2=float(input("나중 부피를 입력하시오. : "))

    T2=(V2*(T1+273))/(V1-273)

    print("----------------------------------------------")
    print("이 기체의 나중온도는",  round(T2, 3) , "°C 입니다.")
    print("----------------------------------------------")

def 기체의분자량_질량을아는경우():
    W=float(input("기체의 질량(g)을 입력하시오. : "))
    P=float(input("기체의 압력(atm)을 입력하시오. : "))
    V=float(input("기체의 부피(L)를 입력하시오. : "))
    T=float(input("기체의 온도(°C)를 입력하시오. : "))

    R=0.082
    M=(W*R*(T+273))/(P*V)

    print("----------------------------------------------")
    print("이 기체의 분자량은",  round(M, 3) , "입니다.")
    print("----------------------------------------------")

def 기체의분자량_밀도를아는경우():
    D=float(input("기체의 밀도(g/L)을 입력하시오. : "))
    P=float(input("기체의 압력(atm)을 입력하시오. : "))
    T=float(input("기체의 온도(°C)를 입력하시오. : "))

    R=0.082
    M=(D*R*(T+273))/P

    print("----------------------------------------------")
    print("이 기체의 분자량은",  round(M, 3) , "입니다.")
    print("----------------------------------------------")

def 퍼센트농도구하는함수():
    A=float(input("용질의 질량(g)을 입력하시오. : "))
    B=float(input("용액의 질량(g)을 입력하시오. : "))

    C=(A/B)*100

    print("----------------------------------------------")
    print("퍼센트농도는",  round(C, 3) , "% 입니다.")
    print("----------------------------------------------")

def PPM농도구하는함수():
    A=float(input("용질의 질량(g)을 입력하시오. : "))
    B=float(input("용액의 질량(g)을 입력하시오. : "))

    C=(A/B)*100000

    print("----------------------------------------------")
    print("PPM농도는",  round(C, 3) , "ppm 입니다.")
    print("----------------------------------------------")

def 몰랄농도구하는함수():
    A=float(input("용질의 양(mol)을 입력하시오. : "))
    B=float(input("용액의 질량(Kg)을 입력하시오. : "))

    C=A/B

    print("----------------------------------------------")
    print("몰랄농도는",  round(C, 3) , "m 입니다.")
    print("----------------------------------------------")
    
def 몰농도구하는함수():
    A=float(input("용질의 양(mol)을 입력하시오. : "))
    B=float(input("용액의 부피(L)를 입력하시오. : "))

    C=A/B
    
    print("----------------------------------------------")
    print("몰농도는",  round(C, 3) , "M 입니다.")
    print("----------------------------------------------")

def 퍼센트농도로몰농도구하는함수():
    A=float(input("퍼센트 농도(%)를 입력하시오(퍼센트기호제외). : "))
    B=float(input("용질의 화학식량을 입력하시오. : "))
    D=float(input("용액의 밀도(g/mL)를 입력하시오. : "))

    C=A/B
    E=(10*A*D)/B

    print("----------------------------------------------")
    print("몰농도는",  round(E, 3) , "M 입니다.")
    print("----------------------------------------------")

def 퍼센트농도로몰랄농도구하는함수():
    A=float(input("퍼센트 농도(%)를 입력하시오(퍼센트기호제외). : "))
    B=float(input("용질의 화학식량을 입력하시오. : "))

    C=((1000*A)/((100-A)*B))

    print("----------------------------------------------")
    print("몰랄농도는",  round(C, 3) , "m 입니다.")
    print("----------------------------------------------")

def 몰농도로몰랄농도구하는함수():
    A=float(input("몰 농도(M)를 입력하시오(몰 제외). : "))
    B=float(input("용질의 화학식량을 입력하시오. : "))
    C=float(input("용액을 밀도(g/mL)를 입력하시오. : "))

    D=((1000*A)/(1000*C-A*B))

    print("----------------------------------------------")
    print("몰랄농도는",  round(D, 3) , "m 입니다.")
    print("----------------------------------------------")

while (True):
    print(science)
    print("----------------------------------------------")
    sciencechoice = input("위의 문장에서 사용해야 할 함수를 고르시오. / 혹은 그만 두시려면 STOP 을 입력하시오. : ")
    print("----------------------------------------------")
    if sciencechoice == "나중부피구하는함수_보일":
        나중부피구하는함수()

    elif sciencechoice == "나중압력구하는함수_보일":
        나중압력구하는함수()

    elif sciencechoice == "나중부피구하는함수_샤를":
        나중부피구하는함수_샤를()

    elif sciencechoice == "나중온도구하는함수_샤를":
        나중온도구하는함수_샤를()

    elif sciencechoice == "기체의분자량_질량을아는경우":
        기체의분자량_질량을아는경우()

    elif sciencechoice == "기체의분자량_밀도를아는경우":
        기체의분자량_밀도를아는경우()

    elif sciencechoice == "퍼센트농도구하는함수":
        퍼센트농도구하는함수()

    elif sciencechoice == "PPM농도구하는함수":
        PPM농도구하는함수()

    elif sciencechoice == "몰랄농도구하는함수":
        몰랄농도구하는함수()

    elif sciencechoice == "몰농도구하는함수":
        몰농도구하는함수()

    elif sciencechoice == "퍼센트농도로몰농도구하는함수":
        퍼센트농도로몰농도구하는함수()

    elif sciencechoice == "퍼센트농도로몰랄농도구하는함수":
        퍼센트농도로몰랄농도구하는함수()

    elif sciencechoice == "몰농도로몰랄농도구하는함수":
        몰농도로몰랄농도구하는함수()

    elif sciencechoice == "STOP" :
        break

    else : 
        print("----------------------------------------------")
        print("입력하신 함수에 대한 정보가 없습니다. 다시 입력해주세요.")
        print("----------------------------------------------")
