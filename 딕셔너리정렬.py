#딕셔너리를 활용한 음식 궁합을 이용하는 방법
foods = {"치킨":"맥주","부침개":"막걸리","회":"소주","스테이크":"와인","짜장면":"단무지","떡볶이":"순대"}

while 1 :
    myfood = input(str(list(foods.keys())) + "중 좋아하는 음식은?")
    if myfood in foods :
        print("*%s* ==>%s<== 입니다." %(myfood,foods.get(myfood)))
    elif myfood== "끝":
        break
    else:
        print("그런 음식은 없습니다. 확인 해 보세요.")
