.<template>
  <div class="container">
    <div class="Nav">
      <div class="item1">
        <div class="ICON"></div>
        <div class="LOGO"></div>
      </div>
      <div style="border: 1px black solid">hihello</div>
    </div>

    <div class="item2">
      <tbody>
        <tr>
          <th>이메일:</th>
          <th><input type="text"></th>
        </tr>
        <tr>
          <th>이름:</th>
          <th><input type="text"></th>
        </tr>
        <tr>
          <th></th>
          <th><button>조회</button></th>
        </tr>
        <tr>
          <th><p></p></th>
        </tr>
        <tr>
          <th>ID:</th>
          <th><input type="text"></th>
        </tr>
        <tr>
          <th>PW:</th>
          <th><input type="text"></th>
        </tr>
        <tr>
          <th>RPi PW:</th>
          <th><input type="text"></th>
        </tr>
      </tbody>
    </div>
  </div>
</template>

<script>
export default {

}
</script>

<style scoped>
.container{
  display: flex;
}
.item1{
  background-color: rgb(169, 201, 202);
  position: absolute;
  width: 20%;
  height: 100%;
  top: 0;
  left: 0;
  display: flex;
}
.ICON{
  /* border: solid 1px black; */
  background-image: url("../assets/ICON_ICANFARM.png");
  background-size: cover;
  position: relative;
  width: 90px;
  height: 100px;
  top: 1%;
  Left: 1%;
}
.LOGO{
  /* border: solid 1px black; */
  background-image: url("../assets/LINE_ICANFARM.png");
  background-size: cover;
  width: 235px;
  height: 39px;
  position: relative;
  left: 6%;
  top: 4%;
  /* margin: auto; */
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
  border-spacing: 20px 20px;
  font-size: 36px;
}
.item2 button{
  display: block;
  margin: 0 auto;
  width: 150px;
}

</style>