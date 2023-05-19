server port(API) : `8090`

## SW 정보

### Jenkins

user : `a206`

passwd : `a206!`

port : 8888

### Mosquitto (MQTT)

port: 3333, 9991

### MongoDB

root : `admin`

root-passwd : `admin123`

user: `icfarm`

passwd : `a206`

port: 27020

### MariaDB

root : `root`

root-passwd : `a206`

database : `farmData`

port :  3336

### Websocket

port : 8090

### nginx (웹)

주소 : [http://k8a206.p.ssafy.io:8081/](http://k8a206.p.ssafy.io:8081/)

port : 8081

## 수동 배포용 스크립트

**netstat -tnlp | grep 8090**

기존에 서비스 중이던 백엔드 kill -9 PID 

```bash
// windows -> unix용 프로젝트로 변환
find . -print | xargs dos2unix

cd Backend/icanfarm
sudo chmod +x gradlew
./gradlew build
cp ~/S08P31A206/Backend/icanfarm/build/libs/*.jar ~/app
cd ~/app
nohup java -jar ~/app/icanfarm-0.0.1-SNAPSHOT.jar 2>&1 &
```

- `cat nohup.out`으로 확인

## MongoDB 접속 + 조회

```jsx
# mongoDB docker 내부에 접속
sudo docker exec -it farm-mongo bash

# mongo shell 접속
mongo -u icfarm -p a206 --authenticationDatabase farmData

# farmData DB로 변경
use farmData

# 데이터 조회 // 콜렉션 이름이 잘 기억 안남,, farmSensor 아닐 수도 있음,,,
db.farmSensor.find().pretty()

# 콜렉션 조회 // farmSensor 아닐 경우 찾기
show collections
```

```bash
# 몽고디비에서 데이터 직접 삽입할 경우 사용
db.farmSensor.insertOne(
{
	hubId: 3,
	name: 'co2',
	value: 25.3,
	date: new Date('2023-05-18T07:00:00Z')
}
)
```

## MariaDB 접속 + 조회

```jsx
# mariaDB docekr접속
sudo docker exec -it farm-maria bash

## farm-maria 아닐수도 있는데 그럴땐
## sudo docker ps로 이름 확인해줘,,

# mariadb client 접속
mysql -u root -p
# 비밀번호 적어주면 됨

## DB랑 테이블 이름 잘 생각 안나니 틀릴 경우 한 번씩 확인해보고 쿼리 날리면 됑 ㅎ
show databases;
use farmData;

show tables;
select * from member;
```
