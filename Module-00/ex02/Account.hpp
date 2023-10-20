/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 20:01:50 by revieira          #+#    #+#             */
/*   Updated: 2023/10/20 14:20:04 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ACCOUNT_H
# define ACCOUNT_H

#include <iostream>
#include <fstream>
#include <sstream>

class Account
{
	public:
		Account();
		Account(const Account &obj);
		Account(int amount);
		~Account();
		Account	&operator=(const Account &other);
		typedef Account	t;

		int			getIndex(void);
		int			getAmount(void);
		int			getDeposits(void);
		int			getWithdrawals(void);

		void		setIndex(int index);
		void		setAmount(int amount);
		void		setDeposits(int deposit);
		void		setWithdrawals(int withdrawals);
		
		static void	displayAccountsInfos(void);
		void		displayStatus(void);
		void		makeDeposit(int deposit);
		void		makeWithdrawal(int withdrawal);

	private:
		int	_index;
		int	_amount;
		int	_deposits;
		int	_withdrawals;
};

#endif
