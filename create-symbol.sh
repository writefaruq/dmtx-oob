#!/bin/bash
echo "Reading local OOB Data...."
hciconfig -a $1 oobdata class > tmp1.txt
bdaddr=$(cat tmp1.txt| grep -m 1 "BD Address:"> tmp2.txt; cut -d" " -f3 tmp2.txt)
hash=$(cat tmp1.txt| grep -m 1 "OOB Hash:"> tmp3.txt; cut -d: -f2 tmp3.txt)   
randomizer=$(cat tmp1.txt| grep -m 1 "Randomizer:"> tmp4.txt; cut -d: -f2 tmp4.txt)
cod=$(cat tmp1.txt| grep -m 1 "Class:"> tmp5.txt; cut -d: -f2 tmp5.txt)
echo "Found BDADDR, Hash, Randomizer:"
echo $bdaddr
echo $hash
echo $randomizer
echo $cod

echo "Creating OOB symbol : oob-symbol.png"
echo "
<?xml version="1.0" encoding="UTF-8" ?>
<!-- Header-->
<bluez-oob>
<oobdatablock>
<mandatorypart>
<!-- Length -->
<length>
    <unit16 value="0x30" />
</length>
<!-- Bluetooth Address (MAC)-->
<bdaddr>
    <text value=\""$bdaddr"\" />
</bdaddr>
</mandatorypart>
<optionalpart>
<!-- Represented as EIR Tags -->
<!-- Class of Device -->
<eirtag>
    <len>
        <unit8 value="0x04" />
    </len>
    <eirdatatype>
        <unit8 value="0x0D" />
    </eirdatatype>
    <eirdata>
        <unit32 value=\""$cod"\" />
    </eirdata>
</eirtag>
<!-- Simple Pairing Hash C -->
<eirtag>
    <len>
        <unit8 value="0x11" />
    </len>
    <eirdatatype>
            <unit8 value="0x0E" />
    </eirdatatype>
    <eirdata>
           <text value=\""$hash"\" />
    </eirdata>
</eirtag>
<!-- Simple Pairing Randomizer R -->
<eirtag>
    <len>
        <unit8 value="0x11" />
    </len>
    <eirdatatype>
            <unit8 value="0x0F" />
    </eirdatatype>
    <eirdata>
           <text value=\""$randomizer"\" />
    </eirdata>
</eirtag>
</optionalpart>
</oobdatablock>
</bluez-oob>

" | dmtxwrite -o oob-symbol.png
rm -rf tmp*.txt