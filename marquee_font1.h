#ifndef MARQUEE_FONT1_H
#define MARQUEE_FONT1_H
//https://www.mikrocontroller.net/topic/54860
byte marqueeFont1[226][8] = {
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},  // U+0020 (space)
{0x04,0x0E,0x0E,0x04,0x04,0x00,0x04,0x00},  // U+0021 (!)        
{0x1B,0x1B,0x12,0x00,0x00,0x00,0x00,0x00},  // U+0022 (")        
{0x00,0x0A,0x1F,0x0A,0x0A,0x1F,0x0A,0x00},  // U+0023 (#)        
{0x08,0x0E,0x10,0x0C,0x02,0x1C,0x04,0x00},  // U+0024 ($)        
{0x19,0x19,0x02,0x04,0x08,0x13,0x13,0x00},  // U+0025 (%)        
{0x08,0x14,0x14,0x08,0x15,0x12,0x0D,0x00},  // U+0026 (&)        
{0x0C,0x0C,0x08,0x00,0x00,0x00,0x00,0x00},  // U+0027 (')        
{0x04,0x08,0x08,0x08,0x08,0x08,0x04,0x00},  // U+0028 (()        
{0x08,0x04,0x04,0x04,0x04,0x04,0x08,0x00},  // U+0029 ())        
{0x00,0x0A,0x0E,0x1F,0x0E,0x0A,0x00,0x00},  // U+002A (*)        
{0x00,0x04,0x04,0x1F,0x04,0x04,0x00,0x00},  // U+002B (+)        
{0x00,0x00,0x00,0x00,0x00,0x0C,0x0C,0x08},  // U+002C (,)        
{0x00,0x00,0x00,0x1F,0x00,0x00,0x00,0x00},  // U+002D (-)        
{0x00,0x00,0x00,0x00,0x00,0x0C,0x0C,0x00},  // U+002E (.)        
{0x00,0x01,0x02,0x04,0x08,0x10,0x00,0x00},  // U+002F (/)        
{0x0E,0x11,0x13,0x15,0x19,0x11,0x0E,0x00},  // U+0030 (0)        
{0x04,0x0C,0x04,0x04,0x04,0x04,0x0E,0x00},  // U+0031 (1)        
{0x0E,0x11,0x01,0x06,0x08,0x10,0x1F,0x00},  // U+0032 (2)        
{0x0E,0x11,0x01,0x0E,0x01,0x11,0x0E,0x00},  // U+0033 (3)        
{0x02,0x06,0x0A,0x12,0x1F,0x02,0x02,0x00},  // U+0034 (4)        
{0x1F,0x10,0x10,0x1E,0x01,0x11,0x0E,0x00},  // U+0035 (5)        
{0x06,0x08,0x10,0x1E,0x11,0x11,0x0E,0x00},  // U+0036 (6)        
{0x1F,0x01,0x02,0x04,0x08,0x08,0x08,0x00},  // U+0037 (7)        
{0x0E,0x11,0x11,0x0E,0x11,0x11,0x0E,0x00},  // U+0038 (8)        
{0x0E,0x11,0x11,0x0F,0x01,0x02,0x0C,0x00},  // U+0039 (9)        
{0x00,0x00,0x0C,0x0C,0x00,0x0C,0x0C,0x00},  // U+003A (:)        
{0x00,0x00,0x0C,0x0C,0x00,0x0C,0x0C,0x08},  // U+003B (;)        
{0x02,0x04,0x08,0x10,0x08,0x04,0x02,0x00},  // U+003C (<)        
{0x00,0x00,0x1F,0x00,0x00,0x1F,0x00,0x00},  // U+003D (=)        
{0x08,0x04,0x02,0x01,0x02,0x04,0x08,0x00},  // U+003E (>)        
{0x0E,0x11,0x01,0x06,0x04,0x00,0x04,0x00},  // U+003F (?)        
{0x0E,0x11,0x17,0x15,0x17,0x10,0x0E,0x00},  // U+0040 (@)        
{0x0E,0x11,0x11,0x11,0x1F,0x11,0x11,0x00},  // U+0041 (A)        
{0x1E,0x11,0x11,0x1E,0x11,0x11,0x1E,0x00},  // U+0042 (B)        
{0x0E,0x11,0x10,0x10,0x10,0x11,0x0E,0x00},  // U+0043 (C)        
{0x1E,0x11,0x11,0x11,0x11,0x11,0x1E,0x00},  // U+0044 (D)        
{0x1F,0x10,0x10,0x1E,0x10,0x10,0x1F,0x00},  // U+0045 (E)        
{0x1F,0x10,0x10,0x1E,0x10,0x10,0x10,0x00},  // U+0046 (F)        
{0x0E,0x11,0x10,0x17,0x11,0x11,0x0F,0x00},  // U+0047 (G)        
{0x11,0x11,0x11,0x1F,0x11,0x11,0x11,0x00},  // U+0048 (H)        
{0x0E,0x04,0x04,0x04,0x04,0x04,0x0E,0x00},  // U+0049 (I)        
{0x01,0x01,0x01,0x01,0x11,0x11,0x0E,0x00},  // U+004A (J)        
{0x11,0x12,0x14,0x18,0x14,0x12,0x11,0x00},  // U+004B (K)        
{0x10,0x10,0x10,0x10,0x10,0x10,0x1F,0x00},  // U+004C (L)        
{0x11,0x1B,0x15,0x11,0x11,0x11,0x11,0x00},  // U+004D (M)        
{0x11,0x19,0x15,0x13,0x11,0x11,0x11,0x00},  // U+004E (N)        
{0x0E,0x11,0x11,0x11,0x11,0x11,0x0E,0x00},  // U+004F (O)        
{0x1E,0x11,0x11,0x1E,0x10,0x10,0x10,0x00},  // U+0050 (P)        
{0x0E,0x11,0x11,0x11,0x15,0x12,0x0D,0x00},  // U+0051 (Q)        
{0x1E,0x11,0x11,0x1E,0x12,0x11,0x11,0x00},  // U+0052 (R)        
{0x0E,0x11,0x10,0x0E,0x01,0x11,0x0E,0x00},  // U+0053 (S)        
{0x1F,0x04,0x04,0x04,0x04,0x04,0x04,0x00},  // U+0054 (T)        
{0x11,0x11,0x11,0x11,0x11,0x11,0x0E,0x00},  // U+0055 (U)        
{0x11,0x11,0x11,0x11,0x11,0x0A,0x04,0x00},  // U+0056 (V)        
{0x11,0x11,0x15,0x15,0x15,0x15,0x0A,0x00},  // U+0057 (W)        
{0x11,0x11,0x0A,0x04,0x0A,0x11,0x11,0x00},  // U+0058 (X)        
{0x11,0x11,0x11,0x0A,0x04,0x04,0x04,0x00},  // U+0059 (Y)        
{0x1E,0x02,0x04,0x08,0x10,0x10,0x1E,0x00},  // U+005A (Z)        
{0x0E,0x08,0x08,0x08,0x08,0x08,0x0E,0x00},  // U+005B ([)        
{0x00,0x10,0x08,0x04,0x02,0x01,0x00,0x00},  // U+005C (\)        
{0x0E,0x02,0x02,0x02,0x02,0x02,0x0E,0x00},  // U+005D (])        
{0x04,0x0A,0x11,0x00,0x00,0x00,0x00,0x00},  // U+005E (^)        
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3F},  // U+005F (_)        
{0x0C,0x0C,0x04,0x00,0x00,0x00,0x00,0x00},  // U+0060 (`)        
{0x00,0x00,0x0E,0x01,0x0F,0x11,0x0F,0x00},  // U+0061 (a)        
{0x10,0x10,0x1E,0x11,0x11,0x11,0x1E,0x00},  // U+0062 (b)        
{0x00,0x00,0x0E,0x11,0x10,0x11,0x0E,0x00},  // U+0063 (c)        
{0x01,0x01,0x0F,0x11,0x11,0x11,0x0F,0x00},  // U+0064 (d)        
{0x00,0x00,0x0E,0x11,0x1E,0x10,0x0E,0x00},  // U+0065 (e)        
{0x06,0x08,0x08,0x1E,0x08,0x08,0x08,0x00},  // U+0066 (f)        
{0x00,0x00,0x0F,0x11,0x11,0x0F,0x01,0x0E},  // U+0067 (g)        
{0x10,0x10,0x1C,0x12,0x12,0x12,0x12,0x00},  // U+0068 (h)        
{0x04,0x00,0x04,0x04,0x04,0x04,0x06,0x00},  // U+0069 (i)        
{0x02,0x00,0x06,0x02,0x02,0x02,0x12,0x0C},  // U+006A (j)        
{0x10,0x10,0x12,0x14,0x18,0x14,0x12,0x00},  // U+006B (k)        
{0x04,0x04,0x04,0x04,0x04,0x04,0x06,0x00},  // U+006C (l)        
{0x00,0x00,0x1A,0x15,0x15,0x11,0x11,0x00},  // U+006D (m)        
{0x00,0x00,0x1C,0x12,0x12,0x12,0x12,0x00},  // U+006E (n)        
{0x00,0x00,0x0E,0x11,0x11,0x11,0x0E,0x00},  // U+006F (o)        
{0x00,0x00,0x1E,0x11,0x11,0x11,0x1E,0x10},  // U+0070 (p)        
{0x00,0x00,0x0F,0x11,0x11,0x11,0x0F,0x01},  // U+0071 (q)        
{0x00,0x00,0x16,0x09,0x08,0x08,0x1C,0x00},  // U+0072 (r)        
{0x00,0x00,0x0E,0x10,0x0E,0x01,0x0E,0x00},  // U+0073 (s)        
{0x00,0x08,0x1E,0x08,0x08,0x0A,0x04,0x00},  // U+0074 (t)        
{0x00,0x00,0x12,0x12,0x12,0x16,0x0A,0x00},  // U+0075 (u)        
{0x00,0x00,0x11,0x11,0x11,0x0A,0x04,0x00},  // U+0076 (v)        
{0x00,0x00,0x11,0x11,0x15,0x1F,0x0A,0x00},  // U+0077 (w)        
{0x00,0x00,0x12,0x12,0x0C,0x12,0x12,0x00},  // U+0078 (x)        
{0x00,0x00,0x12,0x12,0x12,0x0E,0x04,0x18},  // U+0079 (y)        
{0x00,0x00,0x1E,0x02,0x0C,0x10,0x1E,0x00},  // U+007A (z)        
{0x06,0x08,0x08,0x18,0x08,0x08,0x06,0x00},  // U+007B ({)        
{0x04,0x04,0x04,0x00,0x04,0x04,0x04,0x00},  // U+007C (|)        
{0x0C,0x02,0x02,0x03,0x02,0x02,0x0C,0x00},  // U+007D (})        
{0x0A,0x14,0x00,0x00,0x00,0x00,0x00,0x00},  // U+007E (~)        
{0x04,0x0E,0x1B,0x11,0x11,0x1F,0x00,0x00},   // U+007F           
  {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},  // U+0080 (nul)
  {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},  // U+0081
  {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},  // U+0082
  {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},  // U+0083
  {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},  // U+0084
  {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},  // U+0085
  {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},  // U+0086
  {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},  // U+0087
  {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},  // U+0088
  {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},  // U+0089
  {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},  // U+008A
  {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},  // U+008B
  {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},  // U+008C
  {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},  // U+008D
  {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},  // U+008E
  {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},  // U+008F
  {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},  // U+0090
  {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},  // U+0091
  {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},  // U+0092
  {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},  // U+0093
  {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},  // U+0094
  {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},  // U+0095
  {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},  // U+0096
  {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},  // U+0097
  {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},  // U+0098
  {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},  // U+0099
  {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},  // U+009A
  {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},  // U+009B
  {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},  // U+009C
  {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},  // U+009D
  {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},  // U+009E
  {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},  // U+009F
  {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},  // U+00A0 (no break space)
  {0x06,0x06,0x00,0x06,0x06,0x06,0x06,0x00},  // U+00A1 (inverted !)
  {0x04,0x04,0x0f,0x10,0x10,0x0f,0x04,0x04},  // U+00A2 (dollarcents)
  {0x0e,0x0a,0x08,0x1c,0x08,0x19,0x1e,0x00},  // U+00A3 (pound sterling)
  {0x00,0x00,0x11,0x0e,0x0a,0x0e,0x11,0x00},  // U+00A4 (currency mark)
  {0x1b,0x1b,0x0e,0x1f,0x04,0x1f,0x04,0x04},  // U+00A5 (yen)
  {0x06,0x06,0x06,0x00,0x06,0x06,0x06,0x00},  // U+00A6 (broken pipe)
  {0x0e,0x11,0x0c,0x12,0x12,0x0c,0x22,0x1c},  // U+00A7 (paragraph)
  {0x09,0x00,0x00,0x00,0x00,0x00,0x00,0x00},  // U+00A8 (diaeresis)
  {0x0f,0x00,0x06,0x08,0x08,0x06,0x00,0x0f},  // U+00A9 (copyright symbol)
  {0x0e,0x12,0x12,0x0e,0x00,0x00,0x00,0x00},  // U+00AA (superscript a)
  {0x00,0x09,0x12,0x24,0x12,0x09,0x00,0x00},  // U+00AB (<<)
  {0x00,0x00,0x00,0x0f,0x01,0x01,0x00,0x00},  // U+00AC (gun pointing left)
  {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},  // U+00AD (soft hyphen)
  {0x0f,0x00,0x0e,0x09,0x0e,0x09,0x00,0x0f},  // U+00AE (registered symbol)
  {0x1f,0x00,0x00,0x00,0x00,0x00,0x00,0x00},  // U+00AF (macron)
  {0x0e,0x11,0x11,0x0e,0x00,0x00,0x00,0x00},  // U+00B0 (degree)
  {0x04,0x04,0x1f,0x04,0x04,0x00,0x1f,0x00},  // U+00B1 (plusminus)
  {0x0e,0x03,0x06,0x0c,0x0f,0x00,0x00,0x00},  // U+00B2 (superscript 2)
  {0x0e,0x03,0x06,0x03,0x0e,0x00,0x00,0x00},  // U+00B2 (superscript 3)
  {0x06,0x0c,0x00,0x00,0x00,0x00,0x00,0x00},  // U+00B2 (aigu)
  {0x00,0x00,0x09,0x09,0x09,0x0e,0x08,0x10},  // U+00B5 (mu)
  {0x1f,0x2d,0x2d,0x1d,0x0d,0x0d,0x0d,0x00},  // U+00B6 (pilcrow)
  {0x00,0x00,0x00,0x06,0x06,0x00,0x00,0x00},  // U+00B7 (central dot)
  {0x00,0x00,0x00,0x00,0x00,0x06,0x01,0x1e},  // U+00B8 (cedille)
  {0x04,0x0c,0x04,0x0e,0x00,0x00,0x00,0x00},  // U+00B9 (superscript 1)
  {0x0e,0x11,0x11,0x0e,0x00,0x00,0x00,0x00},  // U+00BA (superscript 0)
  {0x00,0x24,0x12,0x09,0x12,0x24,0x00,0x00},  // U+00BB (>>)
  {0x21,0x22,0x26,0x3f,0x1b,0x17,0x27,0x20},  // U+00BC (1/4)
  {0x21,0x22,0x26,0x2e,0x19,0x12,0x26,0x07},  // U+00BD (1/2)
  {0x20,0x11,0x22,0x17,0x2d,0x1b,0x13,0x01},  // U+00BE (3/4)
  {0x04,0x00,0x04,0x08,0x10,0x13,0x0e,0x00},  // U+00BF (inverted ?)
  {0x18,0x00,0x0e,0x11,0x11,0x1f,0x11,0x00},  // U+00C0 (A grave)
  {0x03,0x00,0x0e,0x11,0x11,0x1f,0x11,0x00},  // U+00C1 (A aigu)
  {0x04,0x0a,0x00,0x0e,0x11,0x1f,0x11,0x00},  // U+00C2 (A circumflex)
  {0x0d,0x16,0x00,0x0e,0x11,0x1f,0x11,0x00},  // U+00C3 (A ~)
  {0x11,0x0e,0x0a,0x11,0x1f,0x11,0x11,0x00},  // U+00C4 (A umlaut)
  {0x06,0x06,0x00,0x0e,0x11,0x1f,0x11,0x00},  // U+00C5 (A ring)
  {0x07,0x0a,0x12,0x1f,0x12,0x12,0x13,0x00},  // U+00C6 (AE)
  {0x0e,0x11,0x10,0x11,0x0e,0x06,0x01,0x0e},  // U+00C7 (C cedille)
  {0x18,0x00,0x1f,0x08,0x0e,0x08,0x1f,0x00},  // U+00C8 (E grave)
  {0x03,0x00,0x1f,0x08,0x0e,0x08,0x1f,0x00},  // U+00C9 (E aigu)
  {0x04,0x0a,0x1f,0x08,0x0e,0x08,0x1f,0x00},  // U+00CA (E circumflex)
  {0x0a,0x00,0x1f,0x08,0x0e,0x08,0x1f,0x00},  // U+00CB (E umlaut)
  {0x18,0x00,0x0e,0x04,0x04,0x04,0x0e,0x00},  // U+00CC (I grave)
  {0x06,0x00,0x1c,0x08,0x08,0x08,0x1c,0x00},  // U+00CD (I aigu)
  {0x04,0x0a,0x00,0x0e,0x04,0x04,0x0e,0x00},  // U+00CE (I circumflex)
  {0x11,0x00,0x0e,0x04,0x04,0x04,0x0e,0x00},  // U+00CF (I umlaut)
  {0x1e,0x09,0x1d,0x1d,0x09,0x09,0x1e,0x00},  // U+00D0 (Eth)
  {0x0f,0x00,0x09,0x0d,0x0f,0x0b,0x09,0x00},  // U+00D1 (N ~)
  {0x18,0x00,0x0e,0x11,0x11,0x11,0x0e,0x00},  // U+00D2 (O grave)
  {0x03,0x00,0x0e,0x11,0x11,0x11,0x0e,0x00},  // U+00D3 (O aigu)
  {0x04,0x0a,0x00,0x0e,0x11,0x11,0x0e,0x00},  // U+00D4 (O circumflex)
  {0x0d,0x16,0x00,0x0e,0x11,0x11,0x0e,0x00},  // U+00D5 (O ~)
  {0x11,0x00,0x0e,0x11,0x11,0x11,0x0e,0x00},  // U+00D6 (O umlaut)
  {0x00,0x11,0x0a,0x04,0x0a,0x11,0x00,0x00},  // U+00D7 (multiplicative x)
  {0x0d,0x0a,0x13,0x17,0x1f,0x0a,0x1c,0x00},  // U+00D8 (O stroke)
  {0x18,0x00,0x11,0x11,0x11,0x11,0x0e,0x00},  // U+00D9 (U grave)
  {0x03,0x00,0x11,0x11,0x11,0x11,0x0e,0x00},  // U+00DA (U aigu)
  {0x0e,0x11,0x00,0x11,0x11,0x11,0x0e,0x00},  // U+00DB (U circumflex)
  {0x11,0x00,0x11,0x11,0x11,0x11,0x0e,0x00},  // U+00DC (U umlaut)
  {0x03,0x00,0x1b,0x1b,0x0e,0x04,0x04,0x00},  // U+00DD (Y aigu)
  {0x1c,0x08,0x0e,0x09,0x09,0x0e,0x08,0x1c},  // U+00DE (Thorn)
  {0x00,0x06,0x09,0x0e,0x09,0x0e,0x08,0x08},  // U+00DF (beta)
  {0x18,0x00,0x0c,0x02,0x0e,0x12,0x0f,0x00},  // U+00E0 (a grave)
  {0x06,0x00,0x0c,0x02,0x0e,0x12,0x0f,0x00},  // U+00E1 (a aigu)
  {0x0c,0x12,0x0c,0x02,0x0e,0x12,0x0f,0x00},  // U+00E2 (a circumflex)
  {0x0d,0x16,0x0c,0x02,0x0e,0x12,0x0f,0x00},  // U+00E3 (a ~)
  {0x12,0x00,0x0c,0x02,0x0e,0x12,0x0f,0x00},  // U+00E4 (a umlaut)
  {0x0c,0x0c,0x0c,0x02,0x0e,0x12,0x0f,0x00},  // U+00E5 (a ring)
  {0x00,0x00,0x1f,0x06,0x1f,0x26,0x1f,0x00},  // U+00E6 (ae)
  {0x00,0x00,0x06,0x08,0x08,0x06,0x01,0x06},  // U+00E7 (c cedille)
  {0x0c,0x00,0x06,0x09,0x0f,0x08,0x06,0x00},  // U+00E8 (e grave)
  {0x03,0x00,0x06,0x09,0x0f,0x08,0x06,0x00},  // U+00E9 (e aigu)
  {0x0c,0x12,0x0c,0x12,0x1e,0x10,0x0c,0x00},  // U+00EA (e circumflex)
  {0x09,0x00,0x06,0x09,0x0f,0x08,0x06,0x00},  // U+00EB (e umlaut)
  {0x0c,0x00,0x06,0x02,0x02,0x02,0x07,0x00},  // U+00EC (i grave)
  {0x06,0x00,0x0c,0x04,0x04,0x04,0x0e,0x00},  // U+00ED (i augu)
  {0x04,0x0a,0x00,0x0c,0x04,0x04,0x0e,0x00},  // U+00EE (i circumflex)
  {0x12,0x00,0x0c,0x04,0x04,0x04,0x0e,0x00},  // U+00EF (i umlaut)
  {0x0a,0x06,0x0a,0x01,0x07,0x09,0x06,0x00},  // U+00F0 (eth)
  {0x00,0x0e,0x00,0x0e,0x09,0x09,0x09,0x00},  // U+00F1 (n ~)
  {0x00,0x18,0x00,0x0e,0x11,0x11,0x0e,0x00},  // U+00F2 (o grave)
  {0x00,0x03,0x00,0x0e,0x11,0x11,0x0e,0x00},  // U+00F3 (o aigu)
  {0x04,0x0a,0x00,0x0e,0x11,0x11,0x0e,0x00},  // U+00F4 (o circumflex)
  {0x0d,0x16,0x00,0x0e,0x11,0x11,0x0e,0x00},  // U+00F5 (o ~)
  {0x00,0x11,0x00,0x0e,0x11,0x11,0x0e,0x00},  // U+00F6 (o umlaut)
  {0x04,0x04,0x00,0x1f,0x00,0x04,0x04,0x00},  // U+00F7 (division)
  {0x00,0x02,0x0c,0x16,0x1e,0x1a,0x0c,0x10},  // U+00F8 (o stroke)
  {0x00,0x18,0x00,0x12,0x12,0x12,0x0f,0x00},  // U+00F9 (u grave)
  {0x00,0x06,0x00,0x12,0x12,0x12,0x0f,0x00},  // U+00FA (u aigu)
  {0x0c,0x12,0x00,0x12,0x12,0x12,0x0f,0x00},  // U+00FB (u circumflex)
  {0x00,0x12,0x00,0x12,0x12,0x12,0x0f,0x00},  // U+00FC (u umlaut)
  {0x00,0x03,0x00,0x09,0x09,0x07,0x01,0x0e},  // U+00FD (y aigu)
  {0x00,0x00,0x08,0x0e,0x09,0x0e,0x08,0x00},  // U+00FE (thorn)
  {0x00,0x09,0x00,0x09,0x09,0x07,0x01,0x0e},  // U+00FF (y umlaut)

                      // (the font does not contain any lower case letters. you can add your own.)
                  };    // {}, // 

#endif /* MARQUEE_FONT1_H */

