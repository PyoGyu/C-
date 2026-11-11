//#include<stdio.h>
//int hp = 75;
//int maxHp = 100;
//int stamina = 40;
//bool isInvincible = false;
//
//enum class EAction
//{
//    Idle,
//    Move,
//    Attack,
//    Dodge
//};
//
//EAction action = EAction::Attack;
//
//if (hp <= 0)
//{
//    printf("Dead\n");
//}
//else if (hp >= 1 && hp <= (maxHp * 0.3))
//{
//    printf("Danger\n");
//}
//else
//{
//    printf("Alive\n");
//}
//
//if (isInvincible)
//{
//    printf("Invincible\n");
//}
//
//switch (action)
//{
//    case Idle:
//        printf("Idle\n");
//        break;
//    case Attack:
//        if (stamina >= 30)
//        {
//            printf("Attack Success\n");
//            stamina -= 30;
//        }
//        else
//        {
//            printf("Not Enough Stamina\n");
//        }
//        printf("Attack\n");
//        break;
//    case Move:
//        printf("Move\n");
//        break;
//    case Dodge:
//        printf("Dodge\n");
//        break;
//
//    default:
//        break;
//}