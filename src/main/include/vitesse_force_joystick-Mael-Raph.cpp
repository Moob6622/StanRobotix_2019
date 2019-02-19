#pragma once

double vitesse_force(double input, bool mode) //true = input false = output
{
    /*
    double output;
    int nombredepoint = 9;
    double distancepoint = 1/nombredepoint;
    double saispas = -1;
    double tableau1[100000];
    int espacevitesse2 = 0;
    double espacevitesse1;
    int sepas = 1;
    double espacevitesse3 = 0;
    double sepas1 = 1;
    double espacevitesse4 = -1;
    double distancepointcourbe;
    double distancepointcourbev;
    double distancepointcourbe1;
    double distancepointcourbev1;
    double distancepointcourbe2;
    for (int i = 0; i!=nombredepoint*2; i++)
    {
        saispas = saispas+distancepoint;
        tableau1 [i]=saispas;
    }

    for(int y=0; y!=(nombredepoint*2)+1; y++)
    {
        espacevitesse2 = espacevitesse2+sepas;
        sepas = sepas*2;
    }

    espacevitesse1=1/espacevitesse2;
    sepas1=espacevitesse1;

    for(int w=0; w!=nombredepoint*2; w++)
    {
        espacevitesse3 = espacevitesse3+sepas1;
        sepas1 = sepas1*2;
        if (input <=tableau1 [w])
        {
            w=(nombredepoint*2)-1;
            distancepointcourbe = tableau1 [w]-tableau1 [w-1];
            distancepointcourbe1 = tableau1 [w]-input;
            if (distancepointcourbe<0)
            {
                distancepointcourbe=0-distancepointcourbe;
            }
            if (distancepointcourbe1<0)
            {
                distancepointcourbe1=0-distancepointcourbe1;
            }
            distancepointcourbe2=100*distancepointcourbe1/distancepointcourbe;
            distancepointcourbev=espacevitesse3-espacevitesse4;
            if (distancepointcourbev<0)
            {
                distancepointcourbev=0-distancepointcourbev;
            }
            distancepointcourbev1=distancepointcourbev*distancepointcourbe2/100;
            output = espacevitesse4-distancepointcourbev1;
        }
        espacevitesse4=espacevitesse3;
    }

    */

   srand (static_cast <unsigned> (time(0)));

   float a = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);

   float output = a*pow(input, 3) + (1 - input) * input;
    
    if(mode)
    {
        return input;
    }
    
    //                      Attention: 1 seul return par fonction 
    //                      (sans if, if-else, switch et boucles)
    //                      Si on veut return 2 valeurs, appeler 2 fois
    //                      la fonction avec 2 modes pour 2 valeurs
    //                      en reprenant le meme input (joystick)
    
    else
    {
        return output;
    }             
}