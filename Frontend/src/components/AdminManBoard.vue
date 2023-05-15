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
            <div style="display: flex; align-items: center;">
              <div class="HubIcon" style="margin: 10px;"></div>
              <router-link to="/admin/hub" style="position: relative; width: 80%; text-decoration: none; color: white; font-size: 36px;">허브 등록  &gt;&gt;</router-link>
            </div>
          </div>
          <div>
            <div style="display: flex; align-items: center; background-color: rgb(169, 201, 202);">
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
      <tbody style="width: 80%;">
        <th style="width: 15%;">회원:</th>
        <th style="width: 70%;"><input type="text" placeholder="E-mail을 입력하세요." style="width: 100%; box-sizing: border-box;" v-model="userEmail" @keyup.enter="emailCheck"></th>
        <th style="width: 15%;"><button @click="emailCheck">검색</button></th>
      </tbody>

      <table class="table table-striped table-bordered" style="width: 70%;" v-if="showTable">
        <thead>
          <tr style="font-size: 32px; text-align: center;">
            <th>id</th>
            <th>rpiNickname</th>
            <th>rpiSerial</th>
            <th>joinDate</th>
          </tr>
        </thead>
        <tbody>
          <tr v-for="member in sortedMembers" :key="member.id" style="font-size: 28px; text-align: center;">
            <td>{{ member.id }}</td>
            <td>{{ member.rpiNickname }}</td>
            <td>{{ member.rpiSerial }}</td>
            <!-- <td>{{ member.joinDate }}</td> -->
            <td>
              {{ new Date(member.joinDate).getFullYear() }}년 
              {{ new Date(member.joinDate).getMonth() + 1 }}월 
              {{ new Date(member.joinDate).getDate() }}일 
              {{ new Date(member.joinDate).getHours() }}시
            </td>
          </tr>
        </tbody>
      </table>
    </div>

  </div>
</template>

<script>
import {api} from "@/utils/axios"
import 'bootstrap/dist/css/bootstrap.css';
import 'bootstrap/dist/js/bootstrap.js';

export default {
  data(){
    return {
      userEmail: "",
      members: [],
      showTable: false,
    }
  },
  computed: {
    sortedMembers(){
      return this.members.sort((a, b) => {
        if (a.rpiNickname < b.rpiNickname){
          return -1;
        }
         if (a.rpiNickname > b.rpiNickname){
          return 1;
        }
        return 0;
      });
    },
  },
  methods: {
    emailCheck(){
      api.admin.checkMember(this.userEmail).then((res) => {
        console.log(res.data);
        this.members = res.data;
        this.showTable = true;
      }).catch((err) => {
        console.log(err);
      })
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
::placeholder {
  text-align: center;
}
</style>