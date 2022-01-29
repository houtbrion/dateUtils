# dateUtils

時刻情報を取り扱うライブラリ．

# APIマニュアル

## 構造体等
```
enum {
  SUN = 0,  // 日曜
  MON = 1,  // 月
  TUE = 2,  // 火
  WED = 3,  // 水
  THU = 4,  // 木
  FRI = 5,  // 金
  SAT = 6   // 土
};
```

```
typedef struct  {
  uint16_t  year;        // 年
  uint8_t   month;       // 月
  uint8_t   mday;        // 日
  uint8_t   wday;        // 曜日
  uint8_t   hour;        // 時
  uint8_t   minute;      // 分
  uint8_t   second;      // 秒
  int16_t   millisecond; // ミリ秒
} date_t;
```

## API関数
### UNIX時刻をdate_t型時刻へ変換
```
void unixTimeToDate(unsigned long unixtime, date_t *date);
```

### date_t型時刻をUNIX時間へ変換
```
unsigned long dateToUnixTime(date_t *dateTime);
```

### 時刻を文字列形式で表示
```
String dateString(unsigned long unixTime, uint8_t format=FORMAT_ALL);
```
上記format引数は以下のものを利用(論理演算も可)
```
#define FORMAT_WDAY 0b010
#define FORMAT_TIME 0b001
#define FORMAT_DATE 0b100
#define FORMAT_ALL  0b111
```
デフォルトはFORMAT_ALLで「日付+曜日+時間」を含む文字列に変換する．

以下の例は，曜日なし(日付+時間)の文字列を取得する場合．
```
dateString(unixTime, FORMAT_DATE|FORMAT_TIME);
```









