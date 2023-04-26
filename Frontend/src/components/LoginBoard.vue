.<template>
  <div class="container">
    <div class="item1">
      <div class="ICON"></div>
      <div class="LOGO"></div>
      <!-- <div class="a">start</div> -->
    </div>
    <div class="item2">
      <div>
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
        <div class="d-grid gap-2 col-6 mx-auto">
          <button class="login_btn" type="button" @click="goToMonitor">로그인</button>
        </div>
        <div style="text-align:center;">
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
  margin: 0%;
  width: 40%;
  /* position: absolute; */
}
.ICON{
  border: solid 1px black;
  background-image: url("../assets/ICON_ICANFARM.png");
  background-size: cover;
  width: 135px;
  height: 154px;
  position: relative;
  top: 35px;
  left: 32px;
}
.LOGO{
  border: solid 1px black;
  background-image: url("../assets/LOGO_ICANFARM.png");
  background-size: cover;
  width: 325px;
  height: 554px;
  position: relative;
  top: 276px;
  left: 182px;
}
.a{
  border: solid 1px black;
  position: relative;
  top: 276px;
  left: 182px;
}
.item2{
  background-color: rgb(45, 51, 51);
  width: 60%;
  display: flex;
  align-items: center;
  justify-content: center;
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