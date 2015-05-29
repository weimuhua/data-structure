import java.util.HashSet;
import java.util.Set;
import java.util.regex.Pattern;

public class CheckID {
    private static final String IDENTITY_CODE_PATTEN =
            "^\\d{6}(18|19|20)?\\d{2}(0[1-9]|1[12])(0[1-9]|[12]\\d|3[01])\\d{3}(\\d|X)$";
    private Set<Integer> mProvinceList = new HashSet<Integer>();

    public boolean checkIdentityCode(String code) {
        if (code == null || code.isEmpty()) {
            System.out.println("code illegal, return");
            return false;
        }

        Pattern p = Pattern.compile(IDENTITY_CODE_PATTEN);
        if (!p.matcher(code).matches()) {
            System.out.println("!matches, return");
            return false;
        }

        mProvinceList.add(11/*北京*/);
        mProvinceList.add(12/*天津*/);
        mProvinceList.add(13/*河北*/);
        mProvinceList.add(14/*山西*/);
        mProvinceList.add(15/*内蒙古*/);

        mProvinceList.add(21/*辽宁*/);
        mProvinceList.add(22/*吉林*/);
        mProvinceList.add(23/*黑龙江*/);

        mProvinceList.add(31/*上海*/);
        mProvinceList.add(32/*江苏*/);
        mProvinceList.add(33/*浙江*/);
        mProvinceList.add(34/*安徽*/);
        mProvinceList.add(35/*福建*/);
        mProvinceList.add(36/*江西*/);
        mProvinceList.add(37/*山东*/);

        mProvinceList.add(41/*河南*/);
        mProvinceList.add(42/*湖北*/);
        mProvinceList.add(43/*湖南*/);
        mProvinceList.add(44/*广东*/);
        mProvinceList.add(45/*广西*/);
        mProvinceList.add(46/*海南*/);

        mProvinceList.add(50/*重庆*/);
        mProvinceList.add(51/*四川*/);
        mProvinceList.add(52/*贵州*/);
        mProvinceList.add(53/*云南*/);
        mProvinceList.add(54/*西藏*/);

        mProvinceList.add(61/*山西*/);
        mProvinceList.add(62/*甘肃*/);
        mProvinceList.add(63/*青海*/);
        mProvinceList.add(64/*宁夏*/);
        mProvinceList.add(65/*新疆*/);

        mProvinceList.add(71/*台湾*/);
        mProvinceList.add(81/*香港*/);
        mProvinceList.add(82/*澳门*/);
        mProvinceList.add(91/*国外*/);

        if (!mProvinceList.contains(Integer.parseInt(code.substring(0, 2)))) {
            System.out.println("!mProvinceList contain, return");
            return false;
        }

        if (code.length() == 18) {
            int[] arr = new int[17];
            for (int i = 0; i < 17; i++) {
                arr[i] = Integer.parseInt(String.valueOf(code.charAt(i)));
            }
            //∑(ai×Wi)(mod 11)
            //加权因子
            int[] factor = {7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2};
            //校验位
            char[] parity = {'1', '0', 'X', '9', '8', '7', '6', '5', '4', '3', '2'};
            int sum = 0, ai, wi;
            for (int i = 0; i < 17; i++) {
                ai = arr[i];
                wi = factor[i];
                sum += ai * wi;
            }
            char last = parity[sum % 11];
            if (last != code.charAt(17)) {
                System.out.println("!last char equal, return");
                return false;
            }
        } else {
            return false;
        }

        return true;
    }
}
