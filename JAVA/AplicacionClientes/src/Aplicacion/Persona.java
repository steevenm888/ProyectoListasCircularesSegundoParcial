/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Aplicacion;

import java.io.Serializable;
import java.util.LinkedList;

/**
 *
 * @author t0p01
 */
public class Persona implements Serializable{
    private String firstName;
    private String secondName;
    private String lastname1;
    private String lastname2;
    private String id;
    private String adress;
    private String phoneNumber;
    private char maritalStatus;
    private int birthDay;
    private int birthMonth;
    private int birthYear;
    private boolean gender;
    private final LinkedList<Cuenta> cuentas;

    public Persona() {
        cuentas = new LinkedList<>();
    }

    public String getFirstName() {
        return firstName;
    }

    public LinkedList<Cuenta> getCuentas() {
        return cuentas;
    }
    

    public void setFirstName(String firstName) {
        this.firstName = firstName;
    }

    public String getSecondName() {
        return secondName;
    }

    public void setSecondName(String secondName) {
        this.secondName = secondName;
    }

    public String getLastname1() {
        return lastname1;
    }

    public void setLastname1(String lastname1) {
        this.lastname1 = lastname1;
    }

    public String getLastname2() {
        return lastname2;
    }

    public void setLastname2(String lastname2) {
        this.lastname2 = lastname2;
    }

    public String getId() {
        return id;
    }

    public void setId(String id) {
        this.id = id;
    }

    public String getAdress() {
        return adress;
    }

    public void setAdress(String adress) {
        this.adress = adress;
    }

    public String getPhoneNumber() {
        return phoneNumber;
    }

    public void setPhoneNumber(String phoneNumber) {
        this.phoneNumber = phoneNumber;
    }

    public char getMaritalStatus() {
        return maritalStatus;
    }

    public void setMaritalStatus(char maritalStatus) {
        this.maritalStatus = maritalStatus;
    }

    public int getBirthDay() {
        return birthDay;
    }

    public void setBirthDay(int birthDay) {
        this.birthDay = birthDay;
    }

    public int getBirthMonth() {
        return birthMonth;
    }

    public void setBirthMonth(int birthMonth) {
        this.birthMonth = birthMonth;
    }

    public int getBirthYear() {
        return birthYear;
    }

    public void setBirthYear(int birthYear) {
        this.birthYear = birthYear;
    }

    public boolean isGender() {
        return gender;
    }

    public void setGender(boolean gender) {
        this.gender = gender;
    }

    @Override
    public String toString() {
        String cuentass="";
        char genero;
        if(gender=true){
            genero='M';
        }else{
            genero='F';
        }
        for (int i=0 ;i<cuentas.size();i++){
            cuentass=cuentass+cuentas.get(i).toString()+"\n";
        }
        return "Cliente" + "\nCedula=" + id + "\nNombre=" + firstName + "\nSNombre=" + secondName + "\nApellido=" + lastname1 + "\nSApellido=" + lastname2 + "\nDireccion=" + adress + "\nNumero de Contacto=" + phoneNumber + "\nEstado Civil=" + maritalStatus + "\nDia=" + birthDay + "Mes=" + birthMonth + "Año Nacimiento=" + birthYear + "\nGenero=" + genero + "\nCuentas: \n"+cuentass;
    }
    
    
}
