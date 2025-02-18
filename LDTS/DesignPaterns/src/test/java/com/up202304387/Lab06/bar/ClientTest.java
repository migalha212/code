package com.up202304387.Lab06.bar;

import com.up202304387.Lab06.StringDrink;
import com.up202304387.Lab06.bar.clients.FerengiClient;
import com.up202304387.Lab06.bar.clients.HumanClient;
import com.up202304387.Lab06.bar.clients.RomulanClient;
import com.up202304387.Lab06.stringtranformers.*;
import org.junit.jupiter.api.Test;
import org.mockito.Mockito;

import java.util.ArrayList;
import java.util.List;

import static org.junit.jupiter.api.Assertions.assertEquals;

public class ClientTest {
    @Test
    public void addObserver() {
        Bar bar = new StringBar();
        HumanClient clientMock = Mockito.mock(HumanClient.class);
        bar.addObserver(clientMock);
        Mockito.verify(clientMock,
                Mockito.never()).happyHourStarted(bar);
        Mockito.verify(clientMock,
                Mockito.never()).happyHourEnded(bar);
        bar.startHappyHour();
        Mockito.verify(clientMock,
                Mockito.times(1)).happyHourStarted(bar);
        Mockito.verify(clientMock,
                Mockito.never()).happyHourEnded(bar);
        bar.endHappyHour();
        Mockito.verify(clientMock,
                Mockito.times(1)).happyHourStarted(bar);
        Mockito.verify(clientMock,
                Mockito.times(1)).happyHourEnded(bar);
    }

    @Test
    public void removeObserver() {
        Bar bar = new StringBar();
        HumanClient clientMock = Mockito.mock(HumanClient.class);
        bar.addObserver(clientMock);
        bar.removeObserver(clientMock);
        bar.startHappyHour();
        bar.endHappyHour();
        Mockito.verify(clientMock,
                Mockito.never()).happyHourStarted(bar);
        Mockito.verify(clientMock,
                Mockito.never()).happyHourEnded(bar);
    }

    private StringRecipe getRecipe() {
        StringInverter si = new StringInverter();
        StringCaseChanger cc = new StringCaseChanger();
        StringReplacer sr = new StringReplacer('A', 'X');
        List<StringTransformer> transformers = new ArrayList<>();
        transformers.add(si);
        transformers.add(cc);
        transformers.add(sr);
        StringRecipe recipe = new StringRecipe(transformers);
        return recipe;
    }

    @Test
    public void ferengiAlreadyOpened() {
        StringBar stringBar = new StringBar();
        StringDrink drink = new StringDrink("AbCd-aBcD");
        StringRecipe recipe = getRecipe();
        FerengiClient client = new FerengiClient();
// Recipe is ordered immediately
        stringBar.startHappyHour();
        client.wants(drink, recipe, stringBar);
        assertEquals("dCbX-DcBa", drink.getText());
    }

    @Test
    public void ferengiStartClosed() {
        StringBar stringBar = new StringBar();
        StringDrink drink = new StringDrink("AbCd-aBcD");
        StringRecipe recipe = getRecipe();
        FerengiClient client = new FerengiClient();
        stringBar.addObserver(client); // this is important!
        client.wants(drink, recipe, stringBar);
        assertEquals("AbCd-aBcD", drink.getText());
// Recipe is only ordered here
        stringBar.startHappyHour();
        assertEquals("dCbX-DcBa", drink.getText());
    }

    @Test
    public void romulan() {
        StringBar stringBar = new StringBar();
        StringDrink drink = new StringDrink("AbCd-aBcD");
        StringRecipe recipe = getRecipe();
        RomulanClient client = new RomulanClient();
// Recipe is ordered immediately
        client.wants(drink, recipe, stringBar);
        assertEquals("dCbX-DcBa", drink.getText());
    }
}
