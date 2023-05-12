<template>
  <div class="container">
    <div class="Nav">
      <div>
        <div class="item1" style="background-color: rgb(169, 201, 202);">
          <div class="ICON" style="margin: 10px;"></div>
          <div class="LOGO" style="margin: 5px;"></div>
        </div>
        <div style="margin: 20% 0% 0% 0%;">
          <div style="display: flex; align-items: center;">
            <div class="MemIcon" style="margin: 10px;"></div>
            <router-link to="/admin/member" style="position: relative; width: 80%; text-decoration: none; color: white; font-size: 36px;">회원 등록  &gt;&gt;</router-link>
          </div>
          <div>
            <div style="display: flex; align-items: center; background-color: rgb(169, 201, 202);">
              <div class="HubIcon" style="margin: 10px;"></div>
              <router-link to="/admin/hub" style="position: relative; width: 80%; text-decoration: none; color: white; font-size: 36px;">허브 등록  &gt;&gt;</router-link>
            </div>
          </div>
          <div>
            <div style="display: flex; align-items: center;">
              <div class="MamIcon" style="margin: 10px;"></div>
              <router-link to="/admin/manage" style="position: relative; width: 80%; text-decoration: none; color: white; font-size: 36px;">회원 관리  &gt;&gt;</router-link>
            </div>
          </div>
        </div>
      </div>
      <div><router-link to="/" style="text-decoration: none; color: white; font-size: 48px;">&lt;&lt; LOGIN</router-link></div>
    </div>
    <router-view/>

    <div class="item2">
      <tbody>
        <th>시리얼: </th>
        <th><input type="text" v-model="userSerial"></th>
        <th><button @click="serialCheck">중복확인</button></th>
      </tbody>
      <div style="font-size: 36px; width: 200px;"><button :disabled="!isSerialAvailable" @click="saveSeiral">저장</button></div>

    </div>

  </div>
</template>

<script>
import { api } from "@/utils/axios"

export default {
  data() {
    return{
      userSerial: "",
      isSerialAvailable: false,
    }
  },
  methods: {
    serialCheck(){
      api.admin.checkSerial(this.userSerial).then((res) => {
        alert(res.data);
        this.isSerialAvailable = true;
      }).catch((err) => {
        alert(err.response.data);
        this.isSerialAvailable = false;
      });
    },
    saveSeiral(){
      api.admin.setRPiInfo(this.userSerial).then((res) => {
        alert(res.data);
      }).catch((err) => {
        alert(err.response.data);
      });
    },
  },
}
</script>

<style scoped>
.container{
  display: flex;
}
.Nav{
  background-color: rgb(61, 91, 101);
  position: absolute;
  width: 20%;
  height: 100%;
  top: 0;
  left: 0;
  display: flex;
  flex-direction: column;
  justify-content: space-between;
}
.item1{
  display: flex;
  align-items: center;
}
.ICON{
  background-image: url("../assets/ICON_ICANFARM.png");
  background-size: cover;
  width: 90px;
  height: 100px;
}
.LOGO{
  background-image: url("../assets/LINE_ICANFARM.png");
  background-size: cover;
  width: 235px;
  height: 39px;
}
.MemIcon{
  background-image: url("../assets/ICON_Members.png");
  background-size: cover;
  position: relative; 
  width: 20%;
  height: 70px;
  /* width: 70px;
  height: 70px; */
}
.HubIcon{
  background-image: url("../assets/ICON_Hub.png");
  background-size: cover;
  position: relative; 
  width: 20%;
  height: 70px;
}
.MamIcon{
  background-image: url("../assets/ICON_Member.png");
  background-size: cover;
  position: relative; 
  width: 20%;
  height: 70px;
}

.item2{
  position: absolute;
  width: 80%;
  height: 100%;
  top: 0;
  left: 20%;
  display: flex;
  flex-direction: column;
  justify-content: center;
  align-items: center;
}
.item2 tbody{
  border-spacing: 30px 70px;
  font-size: 36px;
}
.item2 button{
  display: block;
  margin: 0 auto;
  width: 200px;
}


</style>