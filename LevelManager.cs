using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;
using UnityEngine.SceneManagement;

public class LevelManager : MonoBehaviour {

    public Canvas myCanvas;
    public Text grades_Text, finalMean_Text;
    public GameObject first_UI, second_UI, gradeGenerator, gradeGenerated, container, tempContainer;
    public RectTransform generatorRect, containerRect;
    public Button[] grades_Buttons = new Button[13];
    private int[] grades = new int[21];
    private int nGrades, finalMean;
    private float currentSum, roundedMean, rawMean, tfloat;
    private float wantedMean;

    private int[] gradesVector = new int[21];

    private void Start()
    {
        generatorRect = gradeGenerator.GetComponent<RectTransform>();
        first_UI.SetActive(true);
        second_UI.SetActive(false);
        nGrades = 0;
    }

    public void ButtonPressed(int index)
    {
        nGrades++;
        grades[nGrades] = index;
        UpdateGrades();
    }

    public void DeleteLast()
    {
        if (nGrades == 0 || nGrades == 20) return;
        grades[nGrades] = 0;
        nGrades--;
        UpdateGrades();
    }

    public void UpdateGrades()
    {
        int i, j;
        currentSum = 0;
        grades_Text.text = "";
        for (i = 1; i <= nGrades; i++)
        {
            grades_Text.text += grades[i];
            currentSum += grades[i];
            if (i != nGrades) grades_Text.text += ", ";
        }
    }

    public void UpgradeGrades()
    {
        if (wantedMean < 10)
        {
            wantedMean++;
            finalMean_Text.text = "" + (finalMean).ToString("0.00") + " > " + (wantedMean).ToString("0.00");
        }
        CalculateGradesNeeded();
    }

    public void DowngradeGrades()
    {
        if (wantedMean > 1)
        {
            wantedMean--;
            finalMean_Text.text = "" + (finalMean).ToString("0.00") + " > " + (wantedMean).ToString("0.00");
        }
        //GenerateGrades();
        CalculateGradesNeeded();
    }

    public void CalculateGradesNeeded()
    {
        bool im = false;
        int i, j, li = 0;
        for (i = 0; i < 21; i++) gradesVector[i] = 0;
        float gr = 0;
        gr = wantedMean * (nGrades + 1);
        gr -= currentSum;
        
        Debug.Log(gr);
        if (gr > 10)
        {
            gr = gr + 10 * gr / 10;
        }
        while (gr > 10)
        {
            if (gr >= 20)
            {
                gradesVector[++li] = 10;
                gr -= 10;
            }
            else
            {
                gr /= 2;
                gradesVector[++li] = (int)gr;
                gradesVector[++li] = (int)gr;
                GenerateGrades(li, im);
                return;
            }
            
        }
        li++;
        gradesVector[li] = (int)gr;
        if (gr < 0) im = true;
        GenerateGrades(li, im);
    }

    void GenerateGrades(int x, bool imp)
    {
        Destroy(tempContainer);
        generatorRect = gradeGenerator.GetComponent<RectTransform>();
        GameObject tGen;
        tGen = Instantiate(gradeGenerated, generatorRect.position, generatorRect.rotation);
        tGen.GetComponent<Text>().text = "";
        if (imp) tGen.GetComponent<Text>().text = "Imposibil."; else
        for (int i = 1; i <= x; i++)
        {
            tGen.GetComponent<Text>().text += "" + gradesVector[i] + " ";
        }
        tempContainer = Instantiate(container, generatorRect.position, generatorRect.rotation);
        tempContainer.GetComponent<RectTransform>().SetParent(generatorRect.parent, false);
        tempContainer.GetComponent<RectTransform>().anchoredPosition = generatorRect.anchoredPosition;
        tempContainer.GetComponent<RectTransform>().anchoredPosition = new Vector2(generatorRect.anchoredPosition.x + 12f, generatorRect.anchoredPosition.y);
        tGen.GetComponent<RectTransform>().SetParent(tempContainer.GetComponent<RectTransform>(), false);
        tGen.GetComponent<RectTransform>().anchoredPosition = generatorRect.anchoredPosition;
    }

    public void CalculateMean()
    {
        first_UI.SetActive(false);
        second_UI.SetActive(true);
        rawMean = currentSum / nGrades;
        roundedMean = Mathf.RoundToInt(rawMean);
        tfloat = rawMean * 100;
        finalMean = (int)(tfloat);
        finalMean_Text.text = "" + (rawMean).ToString("0.00");
        if (finalMean % 100 != 50) {
            finalMean = (int)roundedMean;
        } else {
            finalMean = (finalMean / 100) + 1;
        }
        finalMean_Text.text += "(" + (finalMean).ToString("0.00") + ")";
        wantedMean = finalMean;
    }

    public void ResetEverything()
    {
        SceneManager.LoadScene(0);
    }

}
