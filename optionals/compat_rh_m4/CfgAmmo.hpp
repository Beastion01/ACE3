class CfgAmmo {

    class Default;
    class BulletCore;
    class BulletBase;
    class B_9x21_Ball;
    class B_556x45_Ball;
    class B_65x39_Caseless;
    class B_762x51_Ball;
    
    class RH_9x19_B_M822: BulletBase
    {
        ACE_caliber=0.009017;
        ACE_bulletLength=0.610;
        ACE_bulletMass=124;
        ACE_ammoTempMuzzleVelocityShifts[]={-2.655, -2.547, -2.285, -2.012, -1.698, -1.280, -0.764, -0.153, 0.596, 1.517, 2.619};
        ACE_ballisticCoefficients[]={0.165};
        ACE_velocityBoundaries[]={};
        ACE_standardAtmosphere="ASM";
        ACE_dragModel=1;
        ACE_muzzleVelocities[]={340, 370, 400};
        ACE_barrelLengths[]={4, 5, 9};
    };
    class RH_9x19_B_HP: BulletBase
    {
        ACE_caliber=0.009017;
        ACE_bulletLength=0.610;
        ACE_bulletMass=124;
        ACE_ammoTempMuzzleVelocityShifts[]={-2.655, -2.547, -2.285, -2.012, -1.698, -1.280, -0.764, -0.153, 0.596, 1.517, 2.619};
        ACE_ballisticCoefficients[]={0.165};
        ACE_velocityBoundaries[]={};
        ACE_standardAtmosphere="ASM";
        ACE_dragModel=1;
        ACE_muzzleVelocities[]={340, 370, 400};
        ACE_barrelLengths[]={4, 5, 9};
    };
    class RH_9x19_B_HPSB: BulletBase
    {
        ACE_caliber=0.009017;
        ACE_bulletLength=0.603;
        ACE_bulletMass=147;
        ACE_ammoTempMuzzleVelocityShifts[]={-2.655, -2.547, -2.285, -2.012, -1.698, -1.280, -0.764, -0.153, 0.596, 1.517, 2.619};
        ACE_ballisticCoefficients[]={0.212};
        ACE_velocityBoundaries[]={};
        ACE_standardAtmosphere="ASM";
        ACE_dragModel=1;
        ACE_muzzleVelocities[]={295, 310, 330};
        ACE_barrelLengths[]={4, 5, 9};
    };
    class RH_556x45_B_M855A1: B_556x45_Ball
    {
        ACE_caliber=0.00569;
        ACE_bulletLength=0.906;
        ACE_bulletMass=62;
        ACE_ammoTempMuzzleVelocityShifts[]={-27.20, -26.44, -23.76, -21.00, -17.54, -13.10, -7.95, -1.62, 6.24, 15.48, 27.75};
        ACE_ballisticCoefficients[]={0.151};
        ACE_velocityBoundaries[]={};
        ACE_standardAtmosphere="ASM";
        ACE_dragModel=7;
        ACE_muzzleVelocities[]={723, 764, 796, 825, 843, 866, 878, 892, 906, 915, 922, 900};
        ACE_barrelLengths[]={8.3, 9.4, 10.6, 11.8, 13.0, 14.2, 15.4, 16.5, 17.7, 18.9, 20.0, 24.0};
    };
    class RH_556x45_B_Mk318: B_556x45_Ball
    {
        ACE_caliber=0.00569;
        ACE_bulletLength=0.906;
        ACE_bulletMass=62;
        ACE_ammoTempMuzzleVelocityShifts[]={-26.55, -25.47, -22.85, -20.12, -16.98, -12.80, -7.64, -1.53, 5.96, 15.17, 26.19};
        ACE_ballisticCoefficients[]={0.307};
        ACE_velocityBoundaries[]={};
        ACE_standardAtmosphere="ASM";
        ACE_dragModel=1;
        ACE_muzzleVelocities[]={780, 886, 950};
        ACE_barrelLengths[]={10, 15.5, 20};
    };
    class RH_556x45_B_Mk262: B_556x45_Ball
    {
        ACE_caliber=0.00569;
        ACE_bulletLength=0.906;
        ACE_bulletMass=77;
        ACE_ammoTempMuzzleVelocityShifts[]={-26.55, -25.47, -22.85, -20.12, -16.98, -12.80, -7.64, -1.53, 5.96, 15.17, 26.19};
        ACE_ballisticCoefficients[]={0.361};
        ACE_velocityBoundaries[]={};
        ACE_standardAtmosphere="ASM";
        ACE_dragModel=1;
        ACE_muzzleVelocities[]={624, 816, 832, 838};
        ACE_barrelLengths[]={7.5, 14.5, 18, 20};
    };
    class RH_68x43_B_FMJ: B_65x39_Caseless
    {
        ACE_caliber=0.007036;
        ACE_bulletLength=0.959;
        ACE_bulletMass=115;
        ACE_ammoTempMuzzleVelocityShifts[]={-26.55, -25.47, -22.85, -20.12, -16.98, -12.80, -7.64, -1.53, 5.96, 15.17, 26.19};
        ACE_ballisticCoefficients[]={0.162};
        ACE_velocityBoundaries[]={};
        ACE_standardAtmosphere="ICAO";
        ACE_dragModel=7;
        ACE_muzzleVelocities[]={713, 785, 810, 850};
        ACE_barrelLengths[]={12, 16, 20, 24};
    };
    class RH_68x43_B_Match: B_65x39_Caseless
    {
        ACE_caliber=0.007036;
        ACE_bulletLength=1.250;
        ACE_bulletMass=135;
        ACE_ammoTempMuzzleVelocityShifts[]={-26.55, -25.47, -22.85, -20.12, -16.98, -12.80, -7.64, -1.53, 5.96, 15.17, 26.19};
        ACE_ballisticCoefficients[]={0.253};
        ACE_velocityBoundaries[]={};
        ACE_standardAtmosphere="ICAO";
        ACE_dragModel=7;
        ACE_muzzleVelocities[]={700, 732, 750, 780};
        ACE_barrelLengths[]={12, 16, 20, 24};
    };	
    class RH_762x35_B_FMJ: B_65x39_Caseless
    {
        ACE_caliber=0.007823;
        ACE_bulletLength=1.118;
        ACE_bulletMass=147;
        ACE_ammoTempMuzzleVelocityShifts[]={-26.55, -25.47, -22.85, -20.12, -16.98, -12.80, -7.64, -1.53, 5.96, 15.17, 26.19};
        ACE_ballisticCoefficients[]={0.398};
        ACE_velocityBoundaries[]={};
        ACE_standardAtmosphere="ICAO";
        ACE_dragModel=1;
        ACE_muzzleVelocities[]={559, 609, 625};
        ACE_barrelLengths[]={6, 16, 20};
    };
    class RH_762x35_B_Match: B_65x39_Caseless
    {
        ACE_caliber=0.007823;
        ACE_bulletLength=1.153;
        ACE_bulletMass=125;
        ACE_ammoTempMuzzleVelocityShifts[]={-26.55, -25.47, -22.85, -20.12, -16.98, -12.80, -7.64, -1.53, 5.96, 15.17, 26.19};
        ACE_ballisticCoefficients[]={0.349, 0.338, 0.330, 0.310};
        ACE_velocityBoundaries[]={792, 610, 488};
        ACE_standardAtmosphere="ICAO";
        ACE_dragModel=1;
        ACE_muzzleVelocities[]={572, 676, 700};
        ACE_barrelLengths[]={6, 16, 20};
    };
    class RH_762x35_B_MSB: B_65x39_Caseless
    {
        ACE_caliber=0.007823;
        ACE_bulletLength=1.489;
        ACE_bulletMass=220;
        ACE_ammoTempMuzzleVelocityShifts[]={-26.55, -25.47, -22.85, -20.12, -16.98, -12.80, -7.64, -1.53, 5.96, 15.17, 26.19};
        ACE_ballisticCoefficients[]={0.608};
        ACE_velocityBoundaries[]={};
        ACE_standardAtmosphere="ICAO";
        ACE_dragModel=1;
        ACE_muzzleVelocities[]={300, 320, 340};
        ACE_barrelLengths[]={9, 16, 20};
    };
    class RH_762x51_B_M80A1: B_762x51_Ball
    {
        ACE_caliber=0.007823;
        ACE_bulletLength=1.14;
        ACE_bulletMass=146;
        ACE_ammoTempMuzzleVelocityShifts[]={-26.55, -25.47, -22.85, -20.12, -16.98, -12.80, -7.64, -1.53, 5.96, 15.17, 26.19};
        ACE_ballisticCoefficients[]={0.2};
        ACE_velocityBoundaries[]={};
        ACE_standardAtmosphere="ICAO";
        ACE_dragModel=7;
        ACE_muzzleVelocities[]={700, 800, 820, 833, 845};
        ACE_barrelLengths[]={10, 16, 20, 24, 26};
    };
    class RH_762x51_B_Mk316LR: B_762x51_Ball
    {
        ACE_caliber=0.007823;
        ACE_bulletLength=1.24;
        ACE_bulletMass=175;
        ACE_ammoTempMuzzleVelocityShifts[]={-5.3, -5.1, -4.6, -4.2, -3.4, -2.6, -1.4, -0.3, 1.4, 3.0, 5.2};
        ACE_ballisticCoefficients[]={0.243};
        ACE_velocityBoundaries[]={};
        ACE_standardAtmosphere="ICAO";
        ACE_dragModel=7;
        ACE_muzzleVelocities[]={775, 790, 805, 810};
        ACE_barrelLengths[]={16, 20, 24, 26};
    };
    class RH_762x51_B_Mk319: B_762x51_Ball
    {
        ACE_caliber=0.007823;
        ACE_bulletLength=1.24;
        ACE_bulletMass=130;
        ACE_ammoTempMuzzleVelocityShifts[]={-2.655, -2.547, -2.285, -2.012, -1.698, -1.280, -0.764, -0.153, 0.596, 1.517, 2.619};
        ACE_ballisticCoefficients[]={0.377};
        ACE_velocityBoundaries[]={};
        ACE_standardAtmosphere="ICAO";
        ACE_dragModel=1;
        ACE_muzzleVelocities[]={838, 892, 910};
        ACE_barrelLengths[]={13, 16, 20};
    };
    class RH_762x51_B_LFMJSB: B_762x51_Ball
    {
        ACE_caliber=0.007823;
        ACE_bulletLength=1.340;
        ACE_bulletMass=200;
        ACE_ammoTempMuzzleVelocityShifts[]={-2.655, -2.547, -2.285, -2.012, -1.698, -1.280, -0.764, -0.153, 0.596, 1.517, 2.619};
        ACE_ballisticCoefficients[]={0.235};
        ACE_velocityBoundaries[]={};
        ACE_standardAtmosphere="ICAO";
        ACE_dragModel=7;
        ACE_muzzleVelocities[]={305, 325, 335, 340};
        ACE_barrelLengths[]={16, 20, 24, 26};
    };
};
