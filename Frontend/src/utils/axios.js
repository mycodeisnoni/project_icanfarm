import axios from "axios";

const request = axios.create({
    baseURL: "http://k8a206.p.ssafy.io:8090",
  })

export const api = {
    member: {
        // 회원 로그인
        // check -> LoginBoard
        login: ({email, passwd}) => {
            return request.post('/api/login', {email, passwd});
        },
        // RPi 비밀번호 조회
        // check -> AccountBoard, RPiBoard
        getRPiPW: (member_id) => {
            return request.get(`/api/rpi/pw/${member_id}`);
        },
        // RPi 비밀번호 저장
        // check -> RPiBoard
        setRPiPW: (member_id, rpi_pw) => {
            return request.post(`/api/rpi/pw/${member_id}`, {pwd: rpi_pw});
        },
        // 허브 리스트
        getHubs: () => {
            return request.get(`/api/hub/${member_id}`);
        },
        // 디폴트 허브 조회
        getDefaultHub: () => {
            return request.get(`/api/hub/default/${member_id}`);
        },
        
    },
    hub: {
        // 온도 설정 조회
        getTempSetting: (rpi_id) => {
            return request.get(`/api/setting/temp/${rpi_id}`);
        },
        // 온도 설정 저장
        setTempSetting: (rpi_id, temp) => {
            return request.post(`/api/setting/temp/${rpi_id}`, {temp});
        },
        // 습도 설정 조회
        getHumidSetting: (rpi_id) => {
            return request.get(`/api/setting/humid/${rpi_id}`);
        },
        // 습도 설정 저장
        setHumidSetting: (rpi_id, humid) => {
            return request.post(`/api/setting/humid/${rpi_id}`, {humid});
        },
        // 조명 설정 조회
        getLightSetting: (rpi_id) => {
            return request.get(`/api/setting/light/${rpi_id}`);
        },
        // 조명 설정 저장
        setLightSetting: (rpi_id, light) => {
            return request.post(`/api/setting/light/${rpi_id}`, {light});
        },
        // 온도 정보 조회
        getTemp: (rpi_id) => {
            return request.get(`/api/temp/${rpi_id}`);
        },
        // 습도 정보 조회
        getHumid: (rpi_id) => {
            return request.get(`/api/humid/${rpi_id}`);
        },
        // CO2 정보 조회
        getCO2: (rpi_id) => {
            return request.get(`/api/co2/${rpi_id}`);
        },
        // 대시보드 로그 조회

    },
    admin: {
        // 라즈베리파이 기기 정보 저장
        setRPiInfo: ({serial}) => {
            return request.post('/admin/rpi', {serial});
        },
        // 회원 정보 저장
        setMember: ({email, passwd, name}) => {
            return request.post('/admin/member', {email, passwd, name});
        },
        // 이메일 중복 확인
        checkEmail: (email) => {
            return request.get(`/admin/validation/email/${email}`);
        },
        // 시리얼 번호 중복 검사
        checkSerial: (serial) => {
            return request.get(`/admin/validation/serial/${serial}`);
        },
        // 회원 정보 조회
        checkMember: (email) => {
            return request.get(`/admin/member/${email}`);
        },
        // RPi 등록
        setMemberRPi: (member_id, tempModule, lightModule) => {
            return request.post('/admin/member/rpi', {member_id, tempModule, lightModule});
        },
        // RPi 제거
        delMemberRPi: (member_id, rpi_id) => {
            return request.delete(`/admin/member/rpi/${member_id}/${rpi_id}`);
        }
    }
}

export default request