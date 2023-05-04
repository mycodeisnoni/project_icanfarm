<template>
  <div>
    <div>
        이메일: 
        <input type="text" name="" id="" v-model="email">
        <button @click="doubleCheck">중복확인</button>
    </div>
    <div>
        PW: 
        <input type="password" v-model="passwd">
    </div>
    <div>
        이름:
        <input type="text" v-model="user_name">
    </div>
    <button @click="saveMember">저장</button>
  </div>
</template>

<script>
import { api } from "@/utils/axios";

export default {
    data(){
        return {
            email: "",
            passwd: "",
            user_name: "",
        }
    },
    methods: {
        doubleCheck(){
            console.log("click");
            api.admin.checkEmail(this.email)
            .then((response) => {
                alert(response.data.message);
            })
            .catch((error) => {
                console.log(error);
            });
        },
        saveMember(){
            api.admin.setMember({email: this.email, passwd: this.passwd, name: this.user_name})
            .then((response) => {
                alert(response.data.message);
            })
            .catch((error) => {
                console.log(error);
            });
        },
    },
}
</script>

<style>

</style>