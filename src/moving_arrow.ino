bool a[8][8];
// int count = 0;
// int char_count=0;

// void setup() {
//   Serial.begin(38400);
//   updateArray('A');
// }
//
// // A, B, C...と順番に出力していく
// void loop() {
//   if (count < 8) {
//     for (int i=0; i<8; i++) {
//       Serial.print(a[i][count]);
//       Serial.println("");
//     }
//     Serial.println("------------------");
//   } else {
//     count = 0;
//     char_count++;
//     updateArray('A'+char_count);
//   }
//   count++;
//   delay(1000);
// }

void updateArray(int n) {
  switch (n) {
    case 126:{
      bool b[8][8] = {
      {0,0,0,1,1,0,0,0},
      {0,0,0,0,1,1,0,0},
      {0,0,0,0,0,1,1,0},
      {1,1,1,1,1,1,1,1},
      {1,1,1,1,1,1,1,1},
      {0,0,0,0,0,1,1,0},
      {0,0,0,0,1,1,0,0},
      {0,0,0,1,1,0,0,0}
      };
      memcpy(a, b, sizeof(b));
      break;
    }
    case 48:{
    bool b[8][8] = {
      {0,0,1,1,1,1,0,0},
      {0,1,0,0,0,0,1,0},
      {0,1,0,0,0,1,1,0},
      {0,1,0,1,1,0,1,0},
      {0,1,1,0,0,0,1,0},
      {0,1,0,0,0,0,1,0},
      {0,0,1,1,1,1,0,0},
      {0,0,0,0,0,0,0,0}
      };
      memcpy(a, b, sizeof(b));
      break;
    }
    case 49:{
      bool b[8][8] = {
      {0,0,0,1,0,0,0,0},
      {0,0,1,1,0,0,0,0},
      {0,0,0,1,0,0,0,0},
      {0,0,0,1,0,0,0,0},
      {0,0,0,1,0,0,0,0},
      {0,0,0,1,0,0,0,0},
      {0,0,1,1,1,0,0,0},
      {0,0,0,0,0,0,0,0}
      };
      memcpy(a, b, sizeof(b));
      break;
    }
    case 50:{
      bool b[8][8] = {
      {0,0,1,1,1,1,0,0},
      {0,1,0,0,0,0,1,0},
      {0,0,0,0,0,0,1,0},
      {0,0,0,0,1,1,0,0},
      {0,0,1,1,0,0,0,0},
      {0,1,0,0,0,0,0,0},
      {0,1,1,1,1,1,1,0},
      {0,0,0,0,0,0,0,0}
      };
      memcpy(a, b, sizeof(b));
      break;
    }
    case 51:{
      bool b[8][8] = {
      {0,0,1,1,1,1,0,0},
      {0,1,0,0,0,0,1,0},
      {0,0,0,0,0,0,1,0},
      {0,0,0,1,1,1,0,0},
      {0,0,0,0,0,0,1,0},
      {0,1,0,0,0,0,1,0},
      {0,0,1,1,1,1,0,0},
      {0,0,0,0,0,0,0,0}
      };
      memcpy(a, b, sizeof(b));
      break;
    }
    case 52:{
      bool b[8][8] = {
      {0,0,0,0,0,1,0,0},
      {0,0,0,0,1,1,0,0},
      {0,0,0,1,0,1,0,0},
      {0,0,1,0,0,1,0,0},
      {0,1,0,0,0,1,0,0},
      {0,1,1,1,1,1,1,0},
      {0,0,0,0,0,1,0,0},
      {0,0,0,0,0,0,0,0}
      };
      memcpy(a, b, sizeof(b));
      break;
    }
    case 53:{
      bool b[8][8] = {
      {0,1,1,1,1,1,1,0},
      {0,1,0,0,0,0,0,0},
      {0,1,1,1,1,1,0,0},
      {0,1,0,0,0,0,1,0},
      {0,0,0,0,0,0,1,0},
      {0,1,0,0,0,0,1,0},
      {0,0,1,1,1,1,0,0},
      {0,0,0,0,0,0,0,0}
      };
      memcpy(a, b, sizeof(b));
      break;
    }
    case 54:{
      bool b[8][8] = {
      {0,0,0,1,1,1,0,0},
      {0,0,1,0,0,0,0,0},
      {0,1,0,0,0,0,0,0},
      {0,1,1,1,1,1,0,0},
      {0,1,0,0,0,0,1,0},
      {0,1,0,0,0,0,1,0},
      {0,0,1,1,1,1,0,0},
      {0,0,0,0,0,0,0,0}
      };
      memcpy(a, b, sizeof(b));
      break;
    }
    case 55:{
      bool b[8][8] = {
      {0,1,1,1,1,1,1,0},
      {0,0,0,0,0,0,1,0},
      {0,0,0,0,0,1,0,0},
      {0,0,0,0,1,0,0,0},
      {0,0,0,0,1,0,0,0},
      {0,0,0,1,0,0,0,0},
      {0,0,0,1,0,0,0,0},
      {0,0,0,0,0,0,0,0}
      };
      memcpy(a, b, sizeof(b));
      break;
    }
    case 56:{
      bool b[8][8] = {
      {0,0,1,1,1,1,0,0},
      {0,1,0,0,0,0,1,0},
      {0,1,0,0,0,0,1,0},
      {0,0,1,1,1,1,0,0},
      {0,1,0,0,0,0,1,0},
      {0,1,0,0,0,0,1,0},
      {0,0,1,1,1,1,0,0},
      {0,0,0,0,0,0,0,0}
      };
      memcpy(a, b, sizeof(b));
      break;
    }
    case 57:{
      bool b[8][8] = {
      {0,0,1,1,1,1,0,0},
      {0,1,0,0,0,0,1,0},
      {0,1,0,0,0,0,1,0},
      {0,0,1,1,1,1,1,0},
      {0,0,0,0,0,0,1,0},
      {0,0,0,0,0,1,0,0},
      {0,0,1,1,1,0,0,0},
      {0,0,0,0,0,0,0,0}
      };
      memcpy(a, b, sizeof(b));
      break;
    }
    case 65:{
      bool b[8][8] = {
      {0,0,0,1,0,0,0,0},
      {0,0,1,0,1,0,0,0},
      {0,0,1,0,1,0,0,0},
      {0,1,0,0,0,1,0,0},
      {0,1,1,1,1,1,1,0},
      {1,0,0,0,0,0,0,0},
      {1,0,0,0,0,0,0,0}
      };
      memcpy(a, b, sizeof(b));
      break;
    }
    case 66:{
      bool b[8][8] = {
      {0,1,1,1,1,1,0,0},
      {0,1,0,0,0,0,1,0},
      {0,1,0,0,0,0,1,0},
      {0,1,1,1,1,1,0,0},
      {0,1,0,0,0,0,1,0},
      {0,1,0,0,0,0,1,0},
      {0,1,1,1,1,1,0,0},
      {0,0,0,0,0,0,0,0}
      };
      memcpy(a, b, sizeof(b));
      break;
    }
    case 67:{
      bool b[8][8] = {
      {0,0,1,1,1,1,0,0},
      {0,1,0,0,0,0,1,0},
      {0,1,0,0,0,0,0,0},
      {0,1,0,0,0,0,0,0},
      {0,1,0,0,0,0,0,0},
      {0,1,0,0,0,0,1,0},
      {0,0,1,1,1,1,0,0},
      {0,0,0,0,0,0,0,0}
      };
      memcpy(a, b, sizeof(b));
      break;
    }
    case 68:{
      bool b[8][8] = {
      {0,1,1,1,1,0,0,0},
      {0,1,0,0,0,1,0,0},
      {0,1,0,0,0,0,1,0},
      {0,1,0,0,0,0,1,0},
      {0,1,0,0,0,0,1,0},
      {0,1,0,0,0,1,0,0},
      {0,1,1,1,1,0,0,0},
      {0,0,0,0,0,0,0,0}
      };
      memcpy(a, b, sizeof(b));
      break;
    }
    case 69:{
      bool b[8][8] = {
      {0,1,1,1,1,1,1,0},
      {0,1,0,0,0,0,0,0},
      {0,1,0,0,0,0,0,0},
      {0,1,1,1,1,1,0,0},
      {0,1,0,0,0,0,0,0},
      {0,1,0,0,0,0,0,0},
      {0,1,1,1,1,1,1,0},
      {0,0,0,0,0,0,0,0}
      };
      memcpy(a, b, sizeof(b));
      break;
    }
    case 70:{
      bool b[8][8] = {
      {0,1,1,1,1,1,1,0},
      {0,1,0,0,0,0,0,0},
      {0,1,0,0,0,0,0,0},
      {0,1,1,1,1,1,0,0},
      {0,1,0,0,0,0,0,0},
      {0,1,0,0,0,0,0,0},
      {0,1,0,0,0,0,0,0},
      {0,0,0,0,0,0,0,0}
      };
      memcpy(a, b, sizeof(b));
      break;
    }
    case 71:{
      bool b[8][8] = {
      {0,0,1,1,1,1,0,0},
      {0,1,0,0,0,0,1,0},
      {0,1,0,0,0,0,0,0},
      {0,1,0,0,1,1,1,0},
      {0,1,0,0,0,0,1,0},
      {0,1,0,0,0,0,1,0},
      {0,0,1,1,1,1,0,0},
      {0,0,0,0,0,0,0,0}
      };
      memcpy(a, b, sizeof(b));
      break;
    }
    case 72:{
      bool b[8][8] = {
      {0,1,0,0,0,0,1,0},
      {0,1,0,0,0,0,1,0},
      {0,1,0,0,0,0,1,0},
      {0,1,1,1,1,1,1,0},
      {0,1,0,0,0,0,1,0},
      {0,1,0,0,0,0,1,0},
      {0,1,0,0,0,0,1,0},
      {0,0,0,0,0,0,0,0}
      };
      memcpy(a, b, sizeof(b));
      break;
    }
    case 73:{
      bool b[8][8] = {
      {0,0,1,1,1,0,0,0},
      {0,0,0,1,0,0,0,0},
      {0,0,0,1,0,0,0,0},
      {0,0,0,1,0,0,0,0},
      {0,0,0,1,0,0,0,0},
      {0,0,0,1,0,0,0,0},
      {0,0,1,1,1,0,0,0},
      {0,0,0,0,0,0,0,0}
      };
      memcpy(a, b, sizeof(b));
      break;
    }
    case 74:{
      bool b[8][8] = {
      {0,0,0,0,0,0,1,0},
      {0,0,0,0,0,0,1,0},
      {0,0,0,0,0,0,1,0},
      {0,0,0,0,0,0,1,0},
      {0,0,0,0,0,0,1,0},
      {0,1,0,0,0,0,1,0},
      {0,0,1,1,1,1,0,0},
      {0,0,0,0,0,0,0,0}
      };
      memcpy(a, b, sizeof(b));
      break;
    }
    case 75:{
      bool b[8][8] = {
      {0,1,0,0,0,0,1,0},
      {0,1,0,0,0,1,0,0},
      {0,1,0,0,1,0,0,0},
      {0,1,0,1,0,0,0,0},
      {0,1,1,0,1,0,0,0},
      {0,1,0,0,0,1,0,0},
      {0,1,0,0,0,0,1,0},
      {0,0,0,0,0,0,0,0}
      };
      memcpy(a, b, sizeof(b));
      break;
    }
    case 76:{
      bool b[8][8] = {
      {0,1,0,0,0,0,0,0},
      {0,1,0,0,0,0,0,0},
      {0,1,0,0,0,0,0,0},
      {0,1,0,0,0,0,0,0},
      {0,1,0,0,0,0,0,0},
      {0,1,0,0,0,0,0,0},
      {0,1,1,1,1,1,1,0},
      {0,0,0,0,0,0,0,0}
      };
      memcpy(a, b, sizeof(b));
      break;
    }
    case 77:{
      bool b[8][8] = {
      {1,0,0,0,0,0,1,0},
      {1,1,0,0,0,1,1,0},
      {1,0,1,0,1,0,1,0},
      {1,0,1,0,1,0,1,0},
      {1,0,0,1,0,0,1,0},
      {1,0,0,1,0,0,1,0},
      {1,0,0,0,0,0,1,0},
      {0,0,0,0,0,0,0,0}
      };
      memcpy(a, b, sizeof(b));
      break;
    }
    case 78:{
      bool b[8][8] = {
      {0,1,0,0,0,0,1,0},
      {0,1,1,0,0,0,1,0},
      {0,1,0,1,0,0,1,0},
      {0,1,0,0,1,0,1,0},
      {0,1,0,0,0,1,1,0},
      {0,1,0,0,0,0,1,0},
      {0,1,0,0,0,0,1,0},
      {0,0,0,0,0,0,0,0}
      };
      memcpy(a, b, sizeof(b));
      break;
    }
    case 79:{
      bool b[8][8] = {
      {0,0,1,1,1,1,0,0},
      {0,1,0,0,0,0,1,0},
      {0,1,0,0,0,0,1,0},
      {0,1,0,0,0,0,1,0},
      {0,1,0,0,0,0,1,0},
      {0,1,0,0,0,0,1,0},
      {0,0,1,1,1,1,0,0},
      {0,0,0,0,0,0,0,0}
      };
      memcpy(a, b, sizeof(b));
      break;
    }
    case 80:{
      bool b[8][8] = {
      {0,1,1,1,1,1,0,0},
      {0,1,0,0,0,0,1,0},
      {0,1,0,0,0,0,1,0},
      {0,1,1,1,1,1,0,0},
      {0,1,0,0,0,0,0,0},
      {0,1,0,0,0,0,0,0},
      {0,1,0,0,0,0,0,0},
      {0,0,0,0,0,0,0,0}
      };
      memcpy(a, b, sizeof(b));
      break;
    }
    case 81:{
      bool b[8][8] = {
      {0,0,1,1,1,1,0,0},
      {0,1,0,0,0,0,1,0},
      {0,1,0,0,0,0,1,0},
      {0,1,0,0,0,0,1,0},
      {0,1,0,0,1,0,1,0},
      {0,1,0,0,0,1,0,0},
      {0,0,1,1,1,0,1,0},
      {0,0,0,0,0,0,0,0}
      };
      memcpy(a, b, sizeof(b));
      break;
    }
    case 82:{
      bool b[8][8] = {
      {0,1,1,1,1,1,0,0},
      {0,1,0,0,0,0,1,0},
      {0,1,0,0,0,0,1,0},
      {0,1,1,1,1,1,0,0},
      {0,1,0,0,1,0,0,0},
      {0,1,0,0,0,1,0,0},
      {0,1,0,0,0,0,1,0},
      {0,0,0,0,0,0,0,0}
      };
      memcpy(a, b, sizeof(b));
      break;
    }
    case 83:{
      bool b[8][8] = {
      {0,0,1,1,1,1,0,0},
      {0,1,0,0,0,0,1,0},
      {0,1,0,0,0,0,0,0},
      {0,0,1,1,1,1,0,0},
      {0,0,0,0,0,0,1,0},
      {0,1,0,0,0,0,1,0},
      {0,0,1,1,1,1,0,0},
      {0,0,0,0,0,0,0,0}
      };
      memcpy(a, b, sizeof(b));
      break;
    }
    case 84:{
      bool b[8][8] = {
      {1,1,1,1,1,1,1,0},
      {0,0,0,1,0,0,0,0},
      {0,0,0,1,0,0,0,0},
      {0,0,0,1,0,0,0,0},
      {0,0,0,1,0,0,0,0},
      {0,0,0,1,0,0,0,0},
      {0,0,0,1,0,0,0,0},
      {0,0,0,0,0,0,0,0}
      };
      memcpy(a, b, sizeof(b));
      break;
    }
    case 85:{
      bool b[8][8] = {
      {0,1,0,0,0,0,1,0},
      {0,1,0,0,0,0,1,0},
      {0,1,0,0,0,0,1,0},
      {0,1,0,0,0,0,1,0},
      {0,1,0,0,0,0,1,0},
      {0,1,0,0,0,0,1,0},
      {0,0,1,1,1,1,0,0},
      {0,0,0,0,0,0,0,0}
      };
      memcpy(a, b, sizeof(b));
      break;
    }
    case 86:{
      bool b[8][8] = {
      {1,0,0,0,0,0,1,0},
      {1,0,0,0,0,0,1,0},
      {0,1,0,0,0,1,0,0},
      {0,1,0,0,0,1,0,0},
      {0,0,1,0,1,0,0,0},
      {0,0,1,0,1,0,0,0},
      {0,0,0,1,0,0,0,0},
      {0,0,0,0,0,0,0,0}
      };
      memcpy(a, b, sizeof(b));
      break;
    }
    case 87:{
      bool b[8][8] = {
      {1,0,0,0,0,0,1,0},
      {1,0,0,1,0,0,1,0},
      {1,0,0,1,0,0,1,0},
      {1,0,1,0,1,0,1,0},
      {1,0,1,0,1,0,1,0},
      {0,1,0,0,0,1,0,0},
      {0,1,0,0,0,1,0,0},
      {0,0,0,0,0,0,0,0}
      };
      memcpy(a, b, sizeof(b));
      break;
    }
    case 88:{
      bool b[8][8] = {
      {1,0,0,0,0,0,1,0},
      {0,1,0,0,0,1,0,0},
      {0,0,1,0,1,0,0,0},
      {0,0,0,1,0,0,0,0},
      {0,0,1,0,1,0,0,0},
      {0,1,0,0,0,1,0,0},
      {1,0,0,0,0,0,1,0},
      {0,0,0,0,0,0,0,0}
      };
      memcpy(a, b, sizeof(b));
      break;
    }
    case 89:{
      bool b[8][8] = {
      {1,0,0,0,0,0,1,0},
      {0,1,0,0,0,1,0,0},
      {0,0,1,0,1,0,0,0},
      {0,0,0,1,0,0,0,0},
      {0,0,0,1,0,0,0,0},
      {0,0,0,1,0,0,0,0},
      {0,0,0,1,0,0,0,0},
      {0,0,0,0,0,0,0,0}
      };
      memcpy(a, b, sizeof(b));
      break;
    }
    case 90:{
      bool b[8][8] = {
      {0,1,1,1,1,1,1,0},
      {0,0,0,0,0,0,1,0},
      {0,0,0,0,0,1,0,0},
      {0,0,0,0,1,0,0,0},
      {0,0,0,1,0,0,0,0},
      {0,0,1,0,0,0,0,0},
      {0,1,1,1,1,1,1,0},
      {0,0,0,0,0,0,0,0}
      };
      memcpy(a, b, sizeof(b));
      break;
    }
    default:
      break;
  }
}
