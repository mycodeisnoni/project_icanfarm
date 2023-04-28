.<template>
  <div class="container">
    <div class="item1">
      <div class="ICON"></div>
      <div class="LOGO"></div>
      <!-- <div class="a">start</div> -->
    </div>
    <div class="item2">
      <div class="login">
        <tbody>
          <tr>
            <th><label class="label" for="id">ID</label></th>
            <th><input type="text" placeholder="User email" v-model="userId"></th>
          </tr>
          <tr>
            <th><label class="label" for="password">PW</label></th>
            <th><input type="password" placeholder="Password" v-model="userPassword"></th>
          </tr>
        </tbody>
        <div class="d-grid gap-2 col-6">
          <button class="login_btn" type="button" @click="goToMonitor">로그인</button>
        </div>
        <div>
          <router-link to="/account" style="text-decoration: none; color: white; font-size: 36px;">ID 조회 | PW 조회 | RPi PW 조회</router-link>
        </div>
        <router-view/>

      </div>
    </div>
  </div>
</template>

<script>
export default {
  name: 'LoginPage',
  data(){
    return{
      userId: '',
      userPassword: '',
    }
  },
  methods:{
    goToMonitor() {
      // console.log(`ID: ${this.userId}, Password: ${this.userPassword}`)
      this.$router.push({name: 'Monitor'})
    }
  }
}
</script>

<style scoped>
.container{
  display: flex;
  /* position: static; */
}
.item1{
  background-color: rgb(169, 201, 202);
  position: absolute;
  width: 40%;
  height: 100%;
  top: 0;
  left: 0;
}
.ICON{
  /* border: solid 1px black; */
  background-image: url("../assets/ICON_ICANFARM.png");
  background-size: cover;
  width: 135px;
  height: 154px;
  top: 2%;
  left: 2%;
}
.LOGO{
  /* border: solid 1px black; */
  background-image: url("../assets/LOGO_ICANFARM.png");
  background-size: cover;
  width: 325px;
  height: 554px;
  margin: auto;
}
.item2{
  background-color: rgb(45, 51, 51);
  position: absolute;
  width: 60%;
  height: 100%;
  top: 0;
  left: 40%;
  display: flex;
  justify-content: center;
  align-items: center;
}
.login{
  border: 1px white solid;

}
.label{
  color: white;
  font-size: 64px;
  margin: 10px 50px;
}
input{
  font-size: 36px;
  /* width: 540px;
  height: 100x; */
}
.login_btn{
  background-color: rgb(90, 100, 100);
  /* width: 400px;
  height: 110px; */
  color: white;
  font-size: 48px;
  text-align: center;
}

</style>