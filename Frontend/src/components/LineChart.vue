<template>
  <div>
    <canvas ref="lineChart" width="800" height="250"></canvas>
  </div>
</template>

<script>
import Chart from 'chart.js/auto';

export default {
  name: 'LineChart',
  props: {
    chartData: {
      type: Object,
      required: true,
    },
    chartOptions: {
      type: Object,
      default: () => ({
        plugins:{
          legend:{
            display: false
          }
        },
      }),
    },
  },
  mounted() {
    this.renderChart();
  },
  methods: {
    renderChart() {
      const canvas = this.$refs.lineChart;
      this.lineChart = new Chart(canvas, {
        type: 'line',
        data: this.chartData,
        options: this.chartOptions,
      });
    },
  },
  beforeDestroy() {
    if (this.lineChart) {
      this.lineChart.destroy();
    }
  },
};
</script>