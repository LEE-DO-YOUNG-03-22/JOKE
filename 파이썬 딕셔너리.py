f={1:"과일", 2:"야채", 3:"생선"}
print(f)

f[4]="고기" #추가 
print(f)

f[2]="육류" #변경
print(f)


####print(f[5]) #딕셔너리명[키] -> 있을시 찾아줌 없으면 오류

print(f.get(5)) #딕셔너리명.get(키) -> 있을시 찾아줌 없으면 None 출력

print(f.keys()) #딕셔너리의 개수
print(list(f.keys())) #딕셔너리의 각각의 이름

print(f.values()) #딕셔너리의 값들만 불러옴
print(list(f.values())) #딕셔너리의 값들만 불러옴 -> 리스트로

print(f.items()) #딕셔너리를 튜플로 만듦 -> 튜플
print(list(f.items())) #딕셔너리를 튜플로 만듦 -> 튜플 ->리스트

print(5 in f) #딕셔너리 안의 값의 여부를 참과 거짓으로 알려줌
