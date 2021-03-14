#define DIM_K (16)
#define ALPHA (0.5f)
float input_data_A[256] = {
  550.0f, 321.0f, 213.0f, 255.0f, 546.0f, 491.0f, 160.0f, 172.0f,
  116.0f, 242.0f, 782.0f, 424.0f, 220.0f, 534.0f, 633.0f, 844.0f,
  985.0f, 46.0f, 644.0f, 199.0f, 431.0f, 943.0f, 794.0f, 407.0f,
  854.0f, 641.0f, 936.0f, 824.0f, 822.0f, 950.0f, 111.0f, 632.0f,
  181.0f, 6.0f, 715.0f, 427.0f, 339.0f, 34.0f, 181.0f, 219.0f,
  92.0f, 578.0f, 507.0f, 462.0f, 946.0f, 429.0f, 751.0f, 971.0f,
  575.0f, 344.0f, 324.0f, 43.0f, 717.0f, 664.0f, 599.0f, 408.0f,
  249.0f, 415.0f, 345.0f, 178.0f, 804.0f, 264.0f, 366.0f, 228.0f,
  184.0f, 534.0f, 187.0f, 28.0f, 662.0f, 245.0f, 532.0f, 318.0f,
  345.0f, 771.0f, 665.0f, 803.0f, 964.0f, 839.0f, 266.0f, 596.0f,
  239.0f, 215.0f, 662.0f, 730.0f, 381.0f, 248.0f, 167.0f, 993.0f,
  142.0f, 372.0f, 710.0f, 494.0f, 902.0f, 748.0f, 882.0f, 345.0f,
  600.0f, 597.0f, 674.0f, 258.0f, 407.0f, 493.0f, 118.0f, 622.0f,
  286.0f, 857.0f, 256.0f, 377.0f, 518.0f, 62.0f, 31.0f, 463.0f,
  374.0f, 704.0f, 662.0f, 363.0f, 108.0f, 214.0f, 772.0f, 301.0f,
  800.0f, 822.0f, 111.0f, 291.0f, 223.0f, 233.0f, 672.0f, 855.0f,
  4.0f, 694.0f, 172.0f, 579.0f, 504.0f, 437.0f, 387.0f, 277.0f,
  943.0f, 391.0f, 376.0f, 790.0f, 912.0f, 670.0f, 971.0f, 958.0f,
  976.0f, 442.0f, 549.0f, 79.0f, 243.0f, 113.0f, 436.0f, 492.0f,
  80.0f, 727.0f, 934.0f, 424.0f, 363.0f, 589.0f, 915.0f, 756.0f,
  965.0f, 753.0f, 620.0f, 499.0f, 405.0f, 19.0f, 245.0f, 827.0f,
  515.0f, 704.0f, 45.0f, 829.0f, 713.0f, 281.0f, 588.0f, 994.0f,
  778.0f, 378.0f, 381.0f, 128.0f, 507.0f, 148.0f, 418.0f, 755.0f,
  603.0f, 128.0f, 411.0f, 215.0f, 513.0f, 182.0f, 946.0f, 414.0f,
  680.0f, 838.0f, 728.0f, 823.0f, 35.0f, 728.0f, 660.0f, 30.0f,
  423.0f, 883.0f, 128.0f, 44.0f, 259.0f, 380.0f, 690.0f, 25.0f,
  29.0f, 946.0f, 269.0f, 267.0f, 953.0f, 841.0f, 33.0f, 150.0f,
  840.0f, 419.0f, 49.0f, 234.0f, 26.0f, 923.0f, 118.0f, 417.0f,
  127.0f, 179.0f, 552.0f, 148.0f, 264.0f, 584.0f, 186.0f, 421.0f,
  474.0f, 279.0f, 238.0f, 991.0f, 961.0f, 281.0f, 27.0f, 623.0f,
  502.0f, 601.0f, 6.0f, 28.0f, 754.0f, 390.0f, 830.0f, 630.0f,
  336.0f, 806.0f, 132.0f, 239.0f, 737.0f, 472.0f, 447.0f, 162.0f,
};
float input_data_B[256] = {
  629.0f, 873.0f, 615.0f, 391.0f, 964.0f, 338.0f, 768.0f, 89.0f,
  411.0f, 961.0f, 968.0f, 617.0f, 949.0f, 572.0f, 333.0f, 329.0f,
  226.0f, 946.0f, 762.0f, 808.0f, 393.0f, 333.0f, 730.0f, 681.0f,
  638.0f, 188.0f, 966.0f, 535.0f, 48.0f, 909.0f, 49.0f, 22.0f,
  326.0f, 45.0f, 827.0f, 504.0f, 639.0f, 973.0f, 170.0f, 167.0f,
  385.0f, 944.0f, 208.0f, 731.0f, 224.0f, 33.0f, 209.0f, 416.0f,
  425.0f, 95.0f, 844.0f, 225.0f, 149.0f, 836.0f, 55.0f, 912.0f,
  634.0f, 739.0f, 618.0f, 364.0f, 542.0f, 690.0f, 408.0f, 666.0f,
  618.0f, 120.0f, 564.0f, 213.0f, 265.0f, 984.0f, 204.0f, 264.0f,
  418.0f, 966.0f, 224.0f, 75.0f, 402.0f, 293.0f, 552.0f, 881.0f,
  46.0f, 508.0f, 604.0f, 936.0f, 710.0f, 243.0f, 896.0f, 116.0f,
  25.0f, 295.0f, 353.0f, 499.0f, 799.0f, 124.0f, 120.0f, 750.0f,
  405.0f, 638.0f, 896.0f, 6.0f, 348.0f, 765.0f, 932.0f, 501.0f,
  437.0f, 924.0f, 896.0f, 887.0f, 30.0f, 380.0f, 177.0f, 248.0f,
  281.0f, 872.0f, 925.0f, 381.0f, 916.0f, 338.0f, 488.0f, 284.0f,
  658.0f, 513.0f, 690.0f, 838.0f, 606.0f, 315.0f, 334.0f, 289.0f,
  492.0f, 574.0f, 2.0f, 236.0f, 935.0f, 746.0f, 166.0f, 565.0f,
  973.0f, 905.0f, 664.0f, 79.0f, 702.0f, 119.0f, 692.0f, 997.0f,
  615.0f, 873.0f, 861.0f, 733.0f, 351.0f, 706.0f, 83.0f, 995.0f,
  436.0f, 792.0f, 608.0f, 211.0f, 780.0f, 339.0f, 954.0f, 476.0f,
  938.0f, 276.0f, 577.0f, 345.0f, 89.0f, 279.0f, 563.0f, 576.0f,
  614.0f, 520.0f, 313.0f, 392.0f, 370.0f, 46.0f, 941.0f, 336.0f,
  844.0f, 390.0f, 113.0f, 948.0f, 188.0f, 57.0f, 926.0f, 831.0f,
  815.0f, 115.0f, 360.0f, 851.0f, 721.0f, 675.0f, 894.0f, 59.0f,
  338.0f, 862.0f, 82.0f, 906.0f, 187.0f, 806.0f, 937.0f, 896.0f,
  986.0f, 39.0f, 349.0f, 273.0f, 324.0f, 981.0f, 602.0f, 149.0f,
  619.0f, 200.0f, 166.0f, 103.0f, 872.0f, 34.0f, 975.0f, 813.0f,
  64.0f, 818.0f, 927.0f, 449.0f, 161.0f, 349.0f, 440.0f, 547.0f,
  382.0f, 518.0f, 728.0f, 22.0f, 444.0f, 331.0f, 621.0f, 948.0f,
  1.0f, 206.0f, 331.0f, 777.0f, 372.0f, 453.0f, 204.0f, 788.0f,
  721.0f, 523.0f, 101.0f, 25.0f, 422.0f, 203.0f, 280.0f, 551.0f,
  303.0f, 570.0f, 436.0f, 668.0f, 437.0f, 972.0f, 608.0f, 679.0f,
};
float verify_data[256] = {
  2083499.0f, 2335773.0f, 2272142.0f, 2030875.5f, 1443809.0f, 1846946.5f, 2213747.0f, 2481535.5f,
  2180235.5f, 2017228.0f, 2250726.0f, 2032947.5f, 1802340.0f, 2082801.0f, 2077960.5f, 1327964.5f,
  2074556.5f, 1991422.0f, 1710411.5f, 1405709.5f, 1893110.5f, 1819924.5f, 2207216.0f, 2320054.5f,
  2020936.5f, 2334088.0f, 2188598.5f, 1789058.0f, 1730877.5f, 1717214.5f, 2091593.5f, 1845256.0f,
  1604234.5f, 2046132.5f, 2294346.0f, 1835145.0f, 1711377.5f, 1913846.0f, 2210233.0f, 2119504.5f,
  1819632.5f, 1950362.0f, 1990740.5f, 2031327.0f, 1567266.5f, 1556063.5f, 1573429.0f, 1487729.0f,
  1024970.5f, 1366300.0f, 1157741.5f, 1289810.0f, 1326560.5f, 1245097.5f, 1563408.5f, 1251452.0f,
  1325346.5f, 1271027.5f, 1265375.5f, 1168103.5f, 1157336.0f, 940731.5f, 1095792.0f, 1114998.5f,
  1964667.0f, 1578696.5f, 1774199.0f, 1253539.0f, 1833272.0f, 1669837.0f, 1938919.5f, 2079591.0f,
  1601042.0f, 2410768.0f, 2141962.0f, 1797552.0f, 1651408.5f, 1681259.0f, 1726605.0f, 1919717.5f,
  1468006.0f, 1878263.0f, 1663206.5f, 1295437.5f, 1672157.5f, 1563168.5f, 2073757.5f, 2148080.0f,
  1599752.5f, 1808943.0f, 2175292.0f, 1657577.5f, 1293723.0f, 1898500.5f, 1268207.0f, 1511351.0f,
  1574490.0f, 1896181.0f, 1711510.0f, 1506244.5f, 1439634.0f, 1681235.5f, 1567510.5f, 1981227.5f,
  1885085.5f, 1709984.5f, 1789919.5f, 1608489.0f, 1514330.0f, 1867212.5f, 1604627.0f, 1458769.0f,
  1796754.5f, 1750174.5f, 1970189.0f, 1604292.0f, 1522194.0f, 1501952.0f, 2016909.0f, 1971130.0f,
  1569296.5f, 1903115.0f, 1810691.5f, 1935830.0f, 1734808.0f, 1468423.0f, 1730995.5f, 1686671.5f,
  1776786.5f, 1936434.5f, 1637063.0f, 1434893.5f, 1900360.5f, 1508530.0f, 2105846.5f, 2209466.0f,
  1959075.0f, 1919706.0f, 2164348.0f, 1799480.0f, 1498660.5f, 1658173.0f, 1702199.5f, 1642331.0f,
  2193462.0f, 2471234.0f, 2563585.5f, 1843405.0f, 2068990.0f, 2488827.5f, 2370144.5f, 2569565.5f,
  2308482.5f, 2738989.5f, 2488822.5f, 2255919.0f, 1874855.5f, 2108588.5f, 2151251.0f, 2063382.0f,
  1501000.5f, 1920352.0f, 2061571.0f, 1776648.5f, 1678435.0f, 1802136.5f, 1675964.5f, 1743067.5f,
  1559185.0f, 2063187.5f, 1945690.0f, 1563966.0f, 1749102.0f, 1493845.5f, 1438045.0f, 1557178.0f,
  1875858.5f, 1944137.5f, 2218250.0f, 1464915.0f, 1885204.0f, 1932591.5f, 1949574.0f, 2102204.5f,
  1732231.0f, 2294586.0f, 2044540.0f, 1848247.0f, 1709565.0f, 1444068.0f, 1708804.0f, 2041164.0f,
  2329887.5f, 2268205.0f, 2782412.5f, 2018037.0f, 2244332.5f, 2711116.0f, 2349830.0f, 2718171.5f,
  2335117.5f, 2917758.5f, 2420514.5f, 2457262.0f, 2239761.0f, 2072954.5f, 2182139.5f, 2700275.0f,
  1851312.5f, 2042275.0f, 1976882.0f, 1768329.5f, 2141145.0f, 1899701.5f, 2126701.0f, 2153713.5f,
  1757276.0f, 2418222.5f, 2299403.5f, 1713945.5f, 1808504.5f, 1748505.0f, 1747642.0f, 2045335.5f,
  2129627.0f, 2282721.0f, 2056444.0f, 2292527.5f, 2201543.0f, 2131348.5f, 2132008.0f, 2269986.5f,
  2370113.0f, 2450448.0f, 2122222.5f, 2024547.5f, 2467681.0f, 1703591.5f, 2346790.0f, 2006883.5f,
  2369273.5f, 2422923.5f, 2780335.0f, 1879370.0f, 2552143.0f, 2383679.0f, 2296813.5f, 2399551.5f,
  2300842.0f, 3075972.5f, 2629257.0f, 2379596.0f, 2262948.0f, 1607246.5f, 2229822.0f, 2249623.5f,
};