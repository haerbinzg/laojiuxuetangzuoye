#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char huangdi[50];//�ʵ۵����ţ�

    int i;          //ѭ�����������ʹ��
    int count = 5;  //��ŵ�ǰ���������
    int currDay = 0;//��Ϸ��ǰ���е��˵ڼ���
    int choice;     //��������û���ѡ��
    int tempCount;  //��ʱ������������źøжȵ���60�ĸ���
    int index = -1; //�������ɾ��������ʱ������
    char name[8];   //��������û����������

    //�������飬�������6���ַ�����ÿ���ַ�������󳤶�Ϊ10���ֽ�
    char names[6][10] = {"��ʩ", "����", "���Ѿ�", "����", "�Է���"};
    //�������飬�������5���ַ�����ÿ���ַ�������󳤶�Ϊ8���ֽ�
    char levelNames[5][8] = {"����", "����", "����", "�ʹ���", "�ʺ�"};
    //�������ÿ�����ӵĵȼ�����levelNames���á�-1��ʾδ����
    int level[] = {0, 2, 0, 0, 0, -1};
    //�������ÿ�����ӵĺøжȣ�-1��ʾδ����
    int loves[] = {100, 100, 100, 100, 100, -1};

    printf("������ʵ۵�������");
    scanf("%s",huangdi);//¼���ַ���ʱ����Ҫ&

    printf("�ʵ۵�������%s\n",huangdi);

    do{

    printf("��%d�죺\n", ++currDay);
    printf("�ʵۼ���\n");
    printf("1�ʵ���ּѡ����\n");       //\t\t(���ӹ���)
    printf("2�����Ƴ��ң�\n");        //\t\t���޸�״̬���ܣ�
    printf("3�������乬�� \n");       //\t \t(ɾ�����ܣ�
    printf("4�������ټ���\n");
    printf("������ѡ��");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:
            printf("�ʵ�������ּѡ����\n");//���ӹ���name���� +1 ��loves���� +1��level���� +1��
            //�ж����鳤���Ƿ�������
            if(count >= 6)
            {
                printf("\n������Ϊ�������»����ٵȵȰɣ�\n\n");
                break;
            }
            printf("����ɽ�������ˣ�������ѡ��~\n");
            printf("�������䣺");
            scanf("%s", name);
            //������Ԫ�ط���count��
            strcpy(names[count], name);
            level[count] = 0;
            loves[count] = 100;
            printf("\n�������ӣ������˺øж�-10\n\n");
            for(i = 0; i < count; i++){
                loves[i] -= 10;
            }
            count++;

            break;

        case 2:

           // printf("2�����Ƴ��ң�\t\t���޸�״̬���ܣ�\n");

             printf("����������Ҫ���ҵ�������");
            scanf("%s", &name);
            for(i = 0; i < count; i++){
                if(strcmp(name, names[i]) == 0){
                    index = i;
                    continue;
                }
                loves[i] -= 10;
            }
            if(index == -1)//û���ҵ�
            {
                printf("\n�����������\n\n");
            }
            else
            {
                loves[index] += 20;
                //ÿ����һ�Σ���������1�������Ϊ4�����ʺ�
                level[index] == 4 ? 4 : level[index]++;
                printf("\n******************************\n");
                printf("Duang~%s�����ȼ�Ϊ��%s\n", names[index], levelNames[level[index]]);
                printf("******************************\n\n");
                printf("��������øж�-10��\n\n");
            }
            index = -1;



                break;

        case 3:
           // printf("3�������乬�� \t \t(ɾ�����ܣ�\n");

            printf("����Ҫ����λ��������乬�أ�");
            scanf("%s", &name);
            for(i = 0; i < count; i++){
                if(strcmp(name, names[i]) == 0){
                   index = i;
                   break;
                }
            }
            if(index == -1)//δ�ҵ�Ҫɾ��������
            {
                printf("\n�龪һ�������˴����乬���óԳԸúȺ�~\n\n");
                break;
            }
            //ִ��ɾ������
            for(i = index; i < count - 1; i++)
            {
                strcpy(names[i], names[i + 1]);
                level[i] = level[i + 1];
                loves[i] = loves[i + 1];
            }
            count--;//������-1
            index = -1;//������������Ϊ��ʼֵ�������´�ʹ��
            printf("\n%s�ѱ������乬��������ů����������øж�+10��\n\n", name);
            for(i = 0; i < count; i++){
                loves[i] += 10;
            }
            index = -1;

            break;

        case 4:

            //printf("4�������ټ���\t\n");

             printf("������Ҫ���ҵ�������");
            scanf("%s", name);
            for(i = 0; i < count; i++)
                {
                if(strcmp(name, names[i]) == 0){
                    printf("\n%s����ĺøж�+10\n\n", name);
                    loves[i] += 10;

                break;

    }}
     printf("����\t�ȼ�\t�øж�\n");
        printf("-----------------------\n");
       /* for(i = 0; i < count; i++){
            printf("%s\t%s\t%d\n", names[i], levelNames[level[i]], loves[i]);
        }*/
        //ÿ�����øжȣ�һ�������������ϵ������øжȵ���60���������ң���Ϸ����
        tempCount = 0;//��ʱ������������źøжȵ���60�ĸ���
        for(i = 0; i < count; i++){
            if(loves[i] < 60)
                tempCount++;
        }

        if(tempCount >= 3){
            printf("���ѵ������������ǣ����ˢ����ȥ�ˣ�\n");
            //ʱ�亯���Ĺ̶��÷�
           /* time_t timep;
            struct tm * p;
            time(&timep);
            p = gmtime(&timep);*/
            printf("�ʵ��䣡��ִ��%d��\n",  currDay);
            exit(0);
        }

    }
    printf("����\t�ȼ�\t�øж�\n");
    printf("-----------------------\n");
    for(i = 0;i < count; i++)
        {
            printf("%12s\t%12s\t%12d\n", names[i] ,levelNames[level[i]] ,loves[i] );
        }



    }while(currDay < 10);


    printf("�ʵ۵ǻ�10��������ȷ�ǡ������˳����檳�Ⱥ����������\n");
    printf("û��û����������������š�������������\n");

    /*for(i = 0; i < count; i++){
        printf("%s\t%s\t%d\n", names[i], levelNames[level[i]], loves[i]);

    }*/





    //printf("Hello world!\n");
    return 0;
}
